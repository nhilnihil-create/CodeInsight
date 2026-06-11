#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
using namespace std;

int Q;

bool judge(long long x, long long score) {
    return x * (x + 1) > score;
}

long long bin_search(long long score, long long left, long long right) {
    if (left + 2 > right) {
        return judge(left, score)? left: right;
    }
    
    long long mid = (left + right) / 2;
    if (judge(mid, score)) {
        return bin_search(score, left, mid);
    } else {
        return bin_search(score, mid, right);
    }
}

int main() {
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int A, B;
        cin >> A >> B;
        long long ans = min(A, B) - 1, score = 1ll * A * B - 1;
        long long x = bin_search(score, min(A, B) + 1, 1e9);
        ans += x - min(A, B) - 1 + score / x;
        cout << ans << endl;
    }
}