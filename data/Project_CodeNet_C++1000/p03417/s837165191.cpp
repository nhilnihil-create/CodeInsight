#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
const ll INF = 1LL<<60;
const ll MOD = 1e9 + 7;


int main() {
    ll N,M;
    cin >> N >> M;
    if (N>=3 && M>=3) cout << (N-2)*(M-2) << endl;
    else if (N==2 || M==2 && N!=1 && M!=1) cout << 0 << endl;
    else if (N==1 && M==1) cout << 1 << endl;
    else if (N==1 || M==1) cout << N*M-2 << endl;
}