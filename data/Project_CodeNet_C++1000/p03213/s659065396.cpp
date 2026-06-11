#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define REPS(i,n) FOR(i,1,n+1)
#define int long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
const int MOD=1e9+7;
const int INF=1e18;

signed main(){
    int N;cin>>N;
    map<int,int>memo;
    REPS(i,N){
        int C=i;
        for(int j=2;j<=sqrt(C);j++){
            while(C%j==0){
                memo[j]++;
                C/=j;
            }
        }
        if(C!=1)memo[C]++;
    }
    int c74=0,c24=0,c14=0,c4=0,c2=0;
    for(auto v:memo){
        if(v.second>=74)c74++;
        if(v.second>=24)c24++;
        if(v.second>=14)c14++;
        if(v.second>=4)c4++;
        if(v.second>=2)c2++;
    }
    int ans=c74+c24*(c2-1)+c14*(c4-1)+c4*(c4-1)*(c2-2)/2;
    cout<<ans<<endl;
}