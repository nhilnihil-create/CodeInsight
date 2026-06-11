/*** author: yuji9511 ***/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lpair = pair<ll, ll>;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i=(m);i<(n);i++)
#define rrep(i,m,n) for(ll i=(m);i>=(n);i--)
#define printa(x,n) for(ll i=0;i<n;i++){cout<<(x[i])<<" \n"[i==n-1];};
void print() {}
template <class H,class... T>
void print(H&& h, T&&... t){cout<<h<<" \n"[sizeof...(t)==0];print(forward<T>(t)...);}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll A[2010];

    rep(i,0,N) cin >> A[i];
    bitset<2000*2000+1> cur(0), nxt(0);
    cur[0] = 1;
    rep(i,0,N){
        nxt = (cur | (cur<<A[i]));
        cur = nxt;
    }

    ll sum = 0;
    rep(i,0,N) sum += A[i];
    ll ans = (sum+1)/2;
    while(1){
        if(cur[ans] == true){
            print(ans);
            return 0;
        }
        ans++;
    }


}