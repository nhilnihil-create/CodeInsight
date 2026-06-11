#include "bits/stdc++.h"

using namespace std;

void Main() {
    int N;
    cin >> N;

    map<int, int> factorization;
    for (int i = 2; i <= N; ++i) {
        int n = i;
        for (int j = 2; j * j <= i; ++j) {
            while (n % j == 0) {
                if (factorization.count(j) == 0) {
                    factorization.insert(make_pair(j, 0));
                }
                factorization[j] += 1;
                n /= j;
            }
        }
        if (n != 1) {
            if (factorization.count(n) == 0) {
                factorization.insert(make_pair(n, 0));
            }
            factorization[n] += 1;
        }
    }
    //for (auto e : factorization) {
    //    cout << e.first << " " << e.second << endl;
    //}

    int more75 = 0;
    int more25 = 0;
    int more15 = 0;
    int more5 = 0;
    int more3 = 0;
    for (auto e : factorization) {
        if (e.second + 1 >= 75) {
            ++more75;
        }
        if (e.second + 1 >= 25) {
            ++more25;
        }
        if (e.second + 1 >= 15) {
            ++more15;
        }
        if (e.second + 1 >= 5) {
            ++more5;
        }
        if (e.second + 1 >= 3) {
            ++more3;
        }
    }
    //cout << more75 << " " << more25 << " " << more15 << " " << more5 << " " << more3 << endl;

    int ans = 0;
    if (more75 > 0) {
        ans += more75;
    }
    if (more25 > 0 && more3 > 0) {
        ans += more25 * (more3 - 1);
    }
    if (more15 > 0 && more5 > 0) {
        ans += more15 * (more5 - 1);
    }
    if (more5 > 1 && more3 > 2) {
        ans += (more5 * (more5 - 1) / 2) * (more3 - 2);
    }
    cout << ans << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
