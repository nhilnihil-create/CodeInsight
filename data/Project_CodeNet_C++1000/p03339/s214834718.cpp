#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    reverse(s.begin(),s.end());
    //cal number of w and e and store and sub pre-proessing
    int W=0,E=0;
    vector<pair<int,int>>v;
    for(int i=0;i<n;i++){
        if(s[i]=='E')E++;
        else W++;
        v.push_back(make_pair(E,W));
    }
    //left same and right opposite
    ll temp,ans=1234567891;
    //took some time but solved in O(n)
    for(int i=0;i<n;i++){
        if(s[i]=='E'){
            if(i==0 || i==n-1){
                temp=v[n-1].second;
            }else{
                temp=v[i-1].first;
                temp+=v[n-1].second-v[i-1].second;
            }
        }else{
            if(i==0 || i==n-1){
                temp=v[n-1].first; //all numbers with east
            }else{
                temp=v[i-1].first;
                temp+=v[n-1].second-v[i].second;
            }
        }
        //cout<<temp<<" ";
        if(temp<ans)ans=temp;
    }
    cout<<ans;
}
