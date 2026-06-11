#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <tuple>
#include <cmath>
#include <iomanip>
#include <map>
#include <stdio.h>
#include <cstring> //memset(dp,0,sizeof(dp))
#include <functional> //operator[]
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define fi first
#define se second
#define pb push_back
#define ALL(a) (a).begin(),(a).end()
using namespace std;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;

signed main(){
    ll n,k; cin >> n >> k;
    ll sum[n];
    queue<ll> q;
    vector<int> cnt(50,0);
    rep(i,n){
        ll a; cin >> a;
        if(i==0) sum[0]=a;
        else sum[i]=sum[i-1]+a;
        q.push(sum[i]);
        rep(j,50){
            if(sum[i]&(1ull<<j)) cnt[j]++;
        }
    }
    rep(i,n){
        for(int j=i+1;j<n;j++){
            ll d=sum[j]-sum[i];
            q.push(d);
            rep(l,50){
                if(d&(1ull<<l)) cnt[l]++;
            }
        }
    }
    
    //bit 50
    ll ans=0;
    for(int i=49;i>=0;i--){
        if(cnt[i]<k) continue;
        ans+=(1ull<<i);
        ll sz=q.size();
        rep(j,sz){
            ll f=q.front(); q.pop();
            if(f&(1ull<<i)) q.push(f);
            else{
                rep(l,50){
                    if(f&(1ull<<l)) cnt[l]--;
                }
            }
        }
    }
    cout << ans << endl;
    
}
