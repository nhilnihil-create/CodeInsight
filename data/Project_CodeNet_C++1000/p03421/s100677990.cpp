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
    ll N,A,B;
    cin >> N >> A >> B;
    vector<ll> ans;
    ll v = (N + A-1) / A;
    if(B >= v && B <= N-A+1){
        ll diff = B - v;
        ll amari = N % A;
        ll cnt = 0;
        ll cur = 1;
        while(diff > 0){
            if(cur % A != amari){
                cur++;
                diff--;
            }else{
                cur++;
            }
        }
        diff = cur-1;
        // if(A != 1){
        //     ll t2 = diff / (A-1);
        //     diff = t2 * A + diff % (A-1);
        // }
        rep(i,0,v){
            rep(j,0,A){
                ll val = (N - (i+1)*A + 1) + j;
                if(val > diff) ans.push_back(val);
            }
        }
        rrep(i,diff,1) ans.push_back(i);
        printa(ans, N);
    }else{
        print(-1);
    }


}