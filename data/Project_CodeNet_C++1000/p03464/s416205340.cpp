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
    ll k;
    cin >> k;
    vll a(k);
    REP(i,k) cin >> a[i];
    ll mx = 2;
    ll mn = 2;
    for(ll i=k-1;i>=0;--i){
        ll x = ((mn-1)/a[i]+1)*a[i];
        if(x>mx){
            cout << -1  << endl;
            return 0;
        }
        ll y = (mx/a[i])*a[i];
        if(y<mn){
            cout << -1 << endl;
            return 0;
        }
        mx = y+a[i]-1;
        mn = x;
    }
    cout << mn << " " << mx << endl;

    return 0;
}