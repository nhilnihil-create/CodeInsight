#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int (i)=(0);(i)<(int)(n);++(i))
using ll = long long;
using P = pair<int, int>;
using namespace std;

int main() {
    ll A, B, K;
    cin >> A >> B >> K;

    rep(i, K) {
        if (i%2 == 0) {
            if (A%2) A--;
            B += A/2;
            A /= 2;
        }
        else {
            if (B%2) B--;
            A += B/2;
            B /= 2;
        }
    }

    cout << A << " " << B << endl;
}
