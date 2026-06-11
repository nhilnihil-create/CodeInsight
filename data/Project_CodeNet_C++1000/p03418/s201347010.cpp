//url:
//problem name:

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
    int N,K; cin >> N >> K;
    ll ans = 0;
    for(int b = 1; b <= N; b++) {
        ans += N/b * max(0,b-K);
        ans += max(0,N%b-K+1);
    }
    if(K == 0) ans -= N;
    cout << ans << endl;
}
