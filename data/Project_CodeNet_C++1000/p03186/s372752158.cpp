#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
using namespace std;
typedef long long ll;
int main() {
int A, B, C; cin >> A >> B >> C;
cout << B+C-max((C-1)-(A+B), 0) << endl;
}