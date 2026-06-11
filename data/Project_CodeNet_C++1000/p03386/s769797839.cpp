#include <bits/stdc++.h>
using namespace std;

int sumDigits(int num) { return num / 10000 + num % 10000 / 1000 + num % 1000 / 100 + num % 100 / 10 + num % 10; }
int main() {
    long long A, B, K;
    cin >> A >> B >> K;
    set<long long> ans;
    int cnt = 0;
    for (long long i = A; i <= B; i++) {
        if (cnt < K) {
            ans.insert(i);
            cnt++;
        } else {
            break;
        }
    }
    cnt = 0;
    for (long long i = B; i >= A; i--) {
        if (cnt < K) {
            ans.insert(i);
            cnt++;
        } else {
            break;
        }
    }
    for (auto i = ans.begin(); i != ans.end(); i++) {
        cout << *i << endl;
    }

    return 0;
}