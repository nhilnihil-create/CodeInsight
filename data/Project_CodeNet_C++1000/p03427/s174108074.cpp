#include <bits/stdc++.h>
using namespace std;
constexpr long long MOD = 1000000007;
using ll = long long;
long long digits(long long n){
    long long result = 0;
    while(n > 0) {
        result++;
        n /= 10;
    }
    return result;
}
int main() {
string s;
cin >> s;
ll st = stoll(s);
ll dig = digits(st);
bool flag = true;
for (ll i = 1; i < s.size();i++){
    if (s[i] != '9') flag = false;
}
ll ans = 0;
ans = (s[0] - '0') + 9 * (dig - 1);
if (!flag) ans--;
cout << ans << endl;

}
