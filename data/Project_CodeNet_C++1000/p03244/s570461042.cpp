#include<bits/stdc++.h>
using namespace std;
#define arep(i,x,n) for(int i=int(x);i<(int)(n);i++)
#define rep(i,n) for(long long i = 0;i < n;++i)
#define pi 3.141592653589793
#define eps 0.00000001
#define INF 1e9+7  
using ll = long long; 
using P=pair<int,int>;
using lP=pair<ll,ll>;
using fP=pair<double,double>;
ll const mod=998244353;
const ll MAX=300000;

bool cmp(P a, P b){
    return a.first>b.first;
}

int main(){
    int n;
    cin>>n;
    vector<P>mp1(100005),mp2(100005);
    rep(i,n){
        mp1[i].first=0;
        mp2[i].first=0;
    }
    rep(i,n){
        int v;
        cin>>v;
        if(i%2==0){
            mp1[v].first++;
            mp1[v].second=v;
        }
        else {
            mp2[v].first++;
            mp2[v].second=v;
        }
    }
        int ans=0;
        sort(mp1.begin(),mp1.end(),cmp);
        sort(mp2.begin(),mp2.end(),cmp);
        int a=mp1[0].second,b=mp2[0].second;
        if(a!=b)ans=n-mp1[0].first-mp2[0].first;
        else ans=n-max(mp1[0].first+mp2[1].first,mp1[1].first+mp2[0].first);
        cout<<ans<<endl;
       // for(auto x:mp1)cout<<x.first<<endl;
    
        
    
    return 0;
}