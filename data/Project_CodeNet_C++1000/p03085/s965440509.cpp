#include <bits/stdc++.h>

#define EPS (1e-10)
#define rep(i, a, b) for (int i = a; i < (int)(b); ++i)
#define rrep(i, a, b) for (int i = b - 1; i >= (int)(a); --i)
#define all(a) a.begin(), a.end()

using namespace std;
using ll = long long;
using vi = vector<int>;
using vb = vector<bool>;
using vll = vector<ll>;
using vd = vector<double>;
using vvi = vector<vi>;
using vvb = vector<vb>;

constexpr int MOD = 1000000007;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    char a;
    cin >> a;

    if (a == 'A') { cout << 'T' << endl; }
    if (a == 'T') { cout << 'A' << endl; }
    if (a == 'C') { cout << 'G' << endl; }
    if (a == 'G') { cout << 'C' << endl; }

    return 0;
}