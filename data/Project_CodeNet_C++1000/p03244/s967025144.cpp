#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define REPS(i,n) FOR(i,1,n+1)
#define RFOR(i,l,r) for(long long i=(l);i>=(r);--i)
#define RREP(i,n) RFOR(i,N-1,0)
#define RREPS(i,n) RFOR(i,N,1)
#define int long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
const int INF=1e18;
const int MOD=1e9+7;
const int MAX=200;
vector<int>G[MAX];
vector<int>color;
bool dfs(int v, int cur = 0){
    color[v] = cur;
    for (auto next_v : G[v]) {
        if (color[next_v] != -1) {
            if (color[next_v] == cur) return false; 
            continue;
        }
        if (!dfs(next_v , 1 - cur)) return false;
    }
    return true;
}

signed main(){
    int N;cin>>N;
    map<int,int>omemo;
    map<int,int>ememo;
    REP(i,N){
        int a;cin>>a;
        if(i%2==0)ememo[a]++;
        if(i%2==1)omemo[a]++;
    }
    int omax=0,osec=0,emax=0,esec=0;
    int oc=0,osc=0,ec=0,esc=0;
    for(auto v:omemo){
        if(v.second>oc){
            osec=omax;
            omax=v.first;
            osc=oc;
            oc=v.second;
            continue;
        }
        if(v.second==oc){
            osec=v.first;
            osc=v.second;
            continue;
        }
        if(v.second>osc){
            osc=v.second;
            osec=v.first;
            continue;
        }
    }
    for(auto v:ememo){
        if(v.second>ec){
            esec=emax;
            emax=v.first;
            esc=ec;
            ec=v.second;
            continue;
        }
        if(v.second==ec){
            esec=v.first;
            esc=v.second;
            continue;
        }
        if(v.second>esc){
            esc=v.second;
            esec=v.first;
            continue;
        }
    }
    if(omax!=emax)cout<<N-oc-ec<<endl;
    else cout<<min(N-oc-esc,N-ec-osc)<<endl;
}