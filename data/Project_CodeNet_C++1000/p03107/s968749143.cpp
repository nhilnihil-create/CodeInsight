#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
ll factorial(int i) {       //階乗
    if (i == 0) return 1;
    return (factorial(i - 1)) * i;
}

int main() {
    string s;
    cin >> s;
    int count_0 = 0;
    int count_1 = 0;
    rep(i, s.size()) s[i] == '0' ? count_0++ : count_1++;
    cout << 2 * min(count_0, count_1) << endl;;
}