#include <bits/stdc++.h>

using namespace std;

vector<int> factor(100 + 1);

void prime_factor(int n) {
    for (int i = 2; i * i <= n; i++)
        while (n % i == 0) {
            factor[i]++;
            n /= i;
        }
    if (n != 1) factor[n] += 1;
}

int num(int n) {
    int ret = 0;
    for (auto x:factor) {
        if (x >= n - 1) ret++;
    }
    return ret;
}

int main() {
    int N;
    cin >> N;

    for (int i = 2; i <= N; i++) {
        prime_factor(i);
    }
    
    cout << num(75) +
            num(25) * (num(3) - 1) +
            num(15) * (num(5) - 1) +
            num(5) * (num(5) - 1) * (num(3) - 2) / 2
         << endl;
    return 0;
}
