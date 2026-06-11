#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define F first
#define S second
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define sizeOf(A) (sizeof(A))/(sizeof(A[0]))
#define odd(x) ((x) % (2))
#define fastio ios_base::sync_with_stdio(false), cin.tie(0);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
const ll MOD = 1e9 + 7;

int main() {
    fastio;

    int a, b, c;
    cin >> a >> b >> c;
    if (a == b) {
        cout << c << "\n";
    } else if (a == c) {
        cout << b << "\n";
    } else {
        cout << a << "\n";
    }
    return 0;
}
