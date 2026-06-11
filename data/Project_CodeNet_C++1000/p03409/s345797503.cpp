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
    vector<pair<int,int>>Red(N);//y,xの順
    vector<pair<int,int>>Blue(N);//x,yの順
    REP(i,N){
        int x,y;cin>>x>>y;
        Red[i]=mp(y,x);
    }
    REP(i,N){
        int x,y;cin>>x>>y;
        Blue[i]=mp(x,y);
    }
    bool Aisused[N];
    bool Bisused[N];
    REP(i,N) Aisused[i]=Bisused[i]=false;
    sort(Red.rbegin(),Red.rend());
    sort(Blue.begin(),Blue.end());
    int ans=0;
    REP(i,N){
        REP(j,N){
            if(Red[i].first<Blue[j].second&&Red[i].second<Blue[j].first&&!Aisused[i]&&!Bisused[j]){
                ans++;
                Aisused[i]=true;
                Bisused[j]=true;
            }
        }
    }
    cout<<ans<<endl;
}
