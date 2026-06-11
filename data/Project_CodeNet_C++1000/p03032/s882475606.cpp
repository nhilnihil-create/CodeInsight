#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    vector<ll> v(n);
    rep(i,n) cin >> v[i];
    ll ans = 0;
    for(int i = 0; i <= min(n,k); ++i){
        for(int j = 0; j <= min(n-i,k-i); ++j){
            priority_queue<ll> pq;
            ll score = 0;
            rep(l,i){
                score += v[l];
                pq.push(-v[l]);
            }
            rep(l,j){
                score += v[n-1-l];
                pq.push(-v[n-1-l]);
            }
            int rest = k - i - j;
            while(!pq.empty() && pq.top() > 0 && rest > 0){
                score += pq.top();
                pq.pop();
                --rest;
            }
            chmax(ans, score);
        }
    }
    cout << ans << endl;
    return 0;
}
