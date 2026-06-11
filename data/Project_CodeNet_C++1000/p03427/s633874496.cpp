#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    string c = "";
    rep(i, s.size())c += '9';
    int ans = 0;
    rep(i, n)rep(j, n){
        rep(k, 10)rep(l, 10){
            string t = c;
            t[i] = '0' + k;
            t[j] = '0' + l;
            if(t <= s){
                int sum = 0;
                rep(m, n){
                    sum += t[m] - '0';
                }
                ans = max(ans, sum);
            }
        }
    }
    cout << ans << endl;
}