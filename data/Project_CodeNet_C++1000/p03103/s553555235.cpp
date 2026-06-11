#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    unsigned long long int n,m;
    cin>>n>>m;
    vector<pair<unsigned long long int,unsigned long long int>>vp;
    for(unsigned long long int i=0;i<n;i++)
    {
        unsigned long long int f,s;
        cin>>f>>s;
        vp.push_back({f,s});
    }
    sort(vp.begin(),vp.end());
    unsigned long long int result=0;
    unsigned long long int index=0;
    while(m){
        if(m>vp[index].second){
            m-=vp[index].second;
            result+=vp[index].first*vp[index].second;
        }
        else{
            result+=vp[index].first*m;
            m=0;
        }
        index++;
    }
    cout<<result;
}