#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

ll N, K;
vector<ll> A;
int main() {
    cin >> N >> K;
    A.resize(N);
    rep(i, N) cin >> A[i];
    
    // 最終的には全て1になる
    // ll left = ceil((double)idx / (K - 1));  
    // ll right = ceil((double)(N - idx - 1) / (K - 1));  
    // ans = left + right;
    cout << ceil((double)(N - 1) / (K - 1)) << endl;
}