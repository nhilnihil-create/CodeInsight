#include <bits/stdc++.h>
using namespace std;

bool isPrime(int x) {
    if(x == 1) return false;

    for (int i = 2; i < x; i++) {
        if(x % i == 0) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    vector<int> Prime;
    for (int i = 2; i <= n; i++) {
        if(isPrime(i)) Prime.push_back(i);
    }
    int m = Prime.size();

    vector<int> divisor(110);

    for (int i = 1; i <= n; i++) {
        int x = i;
        while (x > 1) {
            for (auto d : Prime) {
                if (x % d == 0) {
                    x /= d;
                    divisor[d]++;
                }
            }
        }
    }

    vector<int> comb(110);
    vector<int> a = {2, 4, 14, 24, 74};

    for (auto it : a) {
        for (auto num : divisor) {
            if(num >= it) comb[it]++;
        }
    }

    int ans = 0;
    ans += comb[74];
    ans += comb[24] * (comb[2] - 1);
    ans += comb[14] * (comb[4] - 1);
    ans += (comb[4] * (comb[4] - 1) / 2) * (comb[2] - 2);

    cout << ans << '\n';
}