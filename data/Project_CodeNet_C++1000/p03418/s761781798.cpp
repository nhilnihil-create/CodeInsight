#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(v) (v).begin(),(v).end()
using ll = long long;
using P = pair<int, int>;

int N, K;

int main(){
    cin >> N >> K;
    ll ans = 0;
    for(int i=K+1; i<=N; i++) {
        int p = N / i;
        int r = N % i;
        int c = p * (i - K);
        int d = max(0, r + 1 - K);
        ans += c + d;
        if (K == 0) ans--;
    }
    cout << ans << endl;
    return 0;
}