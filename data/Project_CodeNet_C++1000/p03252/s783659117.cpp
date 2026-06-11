#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define REPS(i,n) FOR(i,0,n+1)
#define int long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
const int MOD=1e9+7;
const int INF=1e18;
const int MAX_N=1e5;

signed main(){
    string S,T;cin>>S>>T;
    map<char,int>sm,tm;
    REP(i,S.size()){
        sm[S[i]]++;
        tm[T[i]]++;
    }
    vector<int>sv,tv;
    for(auto v:sm)sv.pb(v.second);
    for(auto v:tm)tv.pb(v.second);
    sort(sv.begin(),sv.end());
    sort(tv.begin(),tv.end());
    if(sv==tv)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}