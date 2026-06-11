//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

typedef long long ll;
typedef vector<int> vint;
typedef vector<vector<int> > vvint;
typedef vector<long long> vll, vLL;
typedef vector<vector<long long> > vvll, vvLL;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<n;++i)
#define mod (ll)(1e9+7)
#define FIX(a) ((a)%mod+mod)%mod
#define ALL(obj) (obj).begin(), (obj).end()
#define rALL(obj) (obj).rbegin(), (obj).rend()
#define INF 1000000000 //1e9
#define LLINF 2000000000000000000LL //2e18
#define fi first
#define se second
#define pb push_back
int dy[]={0, 0, 1, -1};
int dx[]={1, -1, 0, 0};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll k,n;
    cin >> n >> k;
    vector<pair<ll,ll> > dt(n);
    REP(i,n){
        ll t,d;
        cin >> t >> d;
        t--;
        dt[i] = make_pair(d,t);
    }
    sort(rALL(dt));
    vint used(n,0);
    ll ans=0;
    vll v;
    ll cnt = 0;
    REP(i,k){
        auto p = dt[i];
        ans += p.fi;
        if(used[p.se]==0){
            used[p.se]=1;
            cnt++;
        }else{
            v.pb(p.fi);
        }
    }
    sort(rALL(v));
    ans+=cnt*cnt;
    ll pre = ans;
    int now = k;
    for(int i = cnt+1;i<=k;i++){
        while(now<n){
            ll tmp = ans;
            auto p = dt[now];
            if(used[p.se]==0){
                tmp = pre-v.back()+p.fi+2*cnt+1LL;
                v.pop_back();
                used[p.se]=1;
                ans = max(tmp,ans);
                pre = tmp;
                cnt++;
                now++;
                break;
            }
            now++;
        }
    }
    cout <<  ans << endl;

    return 0;
}