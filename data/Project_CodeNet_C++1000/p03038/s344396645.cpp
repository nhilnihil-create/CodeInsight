#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1001001001LL;
constexpr long long LINF = 1000000000100000000;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){
    int n, m; cin >> n >> m;
    vector<ll> A(n), B(m), C(m);
    ll sum = 0;
    rep(i, n){
        cin >> A[i];
        sum += A[i];
    }
    sort(all(A));
    priority_queue<pll> que;
    rep(i, m){
        ll b, c; cin >>  b >> c;
        que.push({c, b});
    }
    int index = 0;
    rep(i, n){
        if(index >= n || que.empty())break;
        auto p = que.top(); que.pop();
        ll c = p.first, b = p.second;
        rep(j, b){
            if(index >= n)break;
            if(A[index] > c){index = INF; break;}
            sum += c - A[index];
            index++;
        }
    }
    cout << sum << ln;
}