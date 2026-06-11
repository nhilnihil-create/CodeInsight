#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;

int main() {
    string s;
    cin >> s;
    int sum = 0;
    ll digit2 = stoll(s);
    ll digit3 = digit2;
    if (digit3 >= 9) {
        digit2 -= 10;
        digit2 /= 10;
        digit2 *= 10;
        digit2 += 9;
        bool replace = false;
        for (auto ss : s)if (ss != '9')replace = true;
        if (replace)for (int i = 1; i < s.size(); i++)s[i] = '0';
        ll digit = stoll(s);
        if (replace)digit--;
        int sum2 = 0;
        int sum3 = 0;
        while (digit > 9) {
            sum += digit % 10;
            digit /= 10;
        }
        while (digit2 > 9) {
            sum2 += digit2 % 10;
            digit2 /= 10;
        }
        while (digit3 > 9) {
            sum3 += digit3 % 10;
            digit3 /= 10;
        }
        cout << max(digit3 + sum3, max(sum + digit, sum2 + digit2)) << endl;
    }
    else cout << digit3 << endl;
}