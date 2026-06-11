#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define rep(i, N) for (ll i = 0; i < (N); i++)
#define FOR(i, a, b) for (ll i = (a), i < (N): i++)
#define all(A) (A).begin(), (A).end()

int main(){
    int N, A;
    cin >> N >> A;
    N %= 500;
    if (N <= A) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
