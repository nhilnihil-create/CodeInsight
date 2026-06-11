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
    ll N,M;
    cin >> N >> M;
    ll A[10];
    ll num[10] = {0,2,5,5,4,5,6,3,7,6};
    rep(i,0,M) cin >> A[i];
    sort(A, A+M, greater<ll>());
    ll dp[10010] = {};
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    ll nxt[10010] = {};

    rep(i,0,M){
        rep(j,0,N+1){
            if(dp[j - num[A[i]]] == -1) continue;
            if(j - num[A[i]] >= 0){
                if(dp[j - num[A[i]]] + 1 > dp[j]){
                    dp[j] = max(dp[j], dp[j - num[A[i]]] + 1);   
                }
            }
        }
    }
    string ans = "";
    ll idx = N;
    // printa(dp, N+1);
    ll cnt = 0;
    while(idx != 0){
        rep(i,0,M){
            if(cnt == dp[N]-1){
                if(idx - num[A[i]] == 0){
                    ans += to_string(A[i]);
                    idx = 0;
                    break;
                }
            }else{
                if(dp[idx - num[A[i]]] == dp[idx] - 1){
                    ans += to_string(A[i]);
                    // print(ans);
                    idx -= num[A[i]];
                    cnt++;
                    break;
                }
            }
        }
    }
    print(ans);


    

}