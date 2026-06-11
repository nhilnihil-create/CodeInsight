#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int, int>;

int main() {

    int N;
    cin >> N;
    int f = 0;
    int a = N;
    while (a > 0) {
        f += a%10;
        a /= 10;
    }

    if (N%f == 0) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}