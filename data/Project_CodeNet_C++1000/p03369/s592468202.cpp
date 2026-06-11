#include <bits/stdc++.h>
using namespace std;
constexpr long long MOD = 1000000007;
using ll = long long;
int main() {
string s;
cin >> s;
cout << 700 + count(s.begin(), s.end(), 'o') * 100 << endl;
}
