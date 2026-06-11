#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;
using namespace std;

int main(){
    int n;
    cin>>n;
    map<string,int> dict;
    rep(i,n){
        string s;
        cin>>s;
        dict[s]++;
    }   
    int m;
    cin>>m;
    rep(i,m){
        string t;
        cin>>t;
        dict[t]--;
    }
    int maxv=0;
    for(auto itr=dict.begin();itr!=dict.end();itr++){
        maxv=max(maxv,itr->second);
    }
    cout<<maxv<<"\n";
    return 0;
}