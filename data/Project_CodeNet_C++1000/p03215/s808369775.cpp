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
    vll a(n);
    ll num = n*(n+1)/2;
    vll aa(num);
    ll id = 0;
    vll sum(n+1,0);
    REP(i,n){
        cin >> a[i];
        sum[i+1] = sum[i]+a[i];
    }
    REP(i,n){
        for(int j=i;j<n;++j){
            aa[id] = sum[j+1]-sum[i];
            id++;
        }
    }
    vvll ab(num,vll(40,0));
    REP(i,num){
        ll t = aa[i];
        ll now = 0;
        while(t>0){
            ab[i][now] = (t&1);
            now++;
            t >>= 1;
        }
    }
    ll ans  = 0;
    vvll use(num,vll(40, 1));
    for(ll i = 38;i>=0;--i){
        ans <<= 1;
        ll cnt = 0;
        REP(j,num){
            if(ab[j][i]==1&&use[j][i+1]==1){
                cnt++;
            }
        }
        if(cnt>=k){
            REP(j,num){
                if(ab[j][i]==1&&use[j][i+1]==1){
                    use[j][i]=1;
                }else{
                    use[j][i]=0;
                }
            }
            ans+=1;
        }else{
            REP(j,num){
                use[j][i] = use[j][i+1];
            }
        }
    }
    cout << ans << endl;
    return 0;
}