#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define pi 3.14159265359;
#define inf (1 << 21);
#define mod 1000000007;

int main() {
    int N; cin >> N;
    vector<int> p(N);
    int M = 0, ans = 0;
    for (int i = 0; i < N; i++) {
        cin >> p.at(i);
        M = max(M, p.at(i));
        ans += p.at(i);
    }
    ans -= M;
    M /= 2;
    ans += M;
    cout << ans << endl;
}