#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int A[26];
ll mod = 1e9 + 7;

int main() {
    int N; cin >> N;
    string S; cin >> S;
    rep(i, N){
        int a = S[i] - 'a';
        A[a]++;
    }

    ll ans = 1;
    rep(i, 26){
        ans *= A[i] + 1;
        ans %= mod;
    }

    ans--;
    if(ans < 0){
        ans += mod;
    }
    cout << ans << endl;

    return 0;
}