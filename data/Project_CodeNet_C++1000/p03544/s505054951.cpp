#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;

// input
int N;


void input() {
    cin >> N;
}


int main() {
    input();
    vector<ll> w(N + 1);
    w[0] = 2;
    w[1] = 1;
    for (int i = 2; i <= N; i++) w[i] = w[i - 1] + w[i - 2];
    ll ans = w[N];
    cout << ans << endl;
}
