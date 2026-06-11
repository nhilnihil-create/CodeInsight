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
    ll n,k;
    cin >> n >> k;
    ll ans = 0;
    for(ll b = k+1;b<=n;++b){
        ans += b-k;
        ll t;
        if((n-b+1)/b==(n-k)/b){
            t = ((n-b+1)/b)*(b-k);
        }else{
            ll x = ((n-b+1)/b+1)*b;
            t = ((n-b+1)/b) * (x-(n-b+1));
            t+= ((n-k)/b) * (n-k-x+1);
        }
        ans += t;
        //cout << ans << ":" << t << endl;
    }
    if(k==0){
        ans -= n;
    }
    cout << ans << endl;
    return 0;
}