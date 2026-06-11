#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;

// input
int Q;
vector<int> L, R;

const int MAX = 1e5 + 1;


void input() {
    cin >> Q;
    L = R = vector<int>(Q);
    rep(i, Q) cin >> L[i] >> R[i];
}


bool is_prime(int num) {
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false;
    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}


int main() {
    input();
    vector<int> w(MAX, 0);
    for (int i = 1; i < MAX; i++) {
        w[i] = w[i - 1];
        if (is_prime(i) && is_prime((i + 1) / 2)) w[i]++;
    }
    rep(i, Q) {
        int ans = w[R[i]] - w[L[i] - 1];
        printf("%d\n", ans);
    }
}
