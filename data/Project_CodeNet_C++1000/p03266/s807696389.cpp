#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (n); ++i)
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Pl = pair<long long,long long>;
using veci = vector<int>;
using vecl = vector<long>;
using vecveci = vector<vector<int>>;
using vecvecl = vector<vector<long long>>;

int main() {
    ll N,K; cin >> N >> K;
    if(K%2 != 0) cout << N/K*(N/K)*(N/K) << endl;
    else {
        ll cnt = 0;
        for(ll i = 1; i <= N; i++) {
            if(i%K == K/2) cnt++;
        }
        cout << (N/K)*(N/K)*(N/K) + cnt*cnt*cnt << endl;
    }
}
