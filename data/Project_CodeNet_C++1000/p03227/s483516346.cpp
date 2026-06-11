#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    string s;
    cin >> s;
    int n = s.length();
    if(n == 2) cout << s << endl;
    if(n == 3) {
        reverse(s.begin(), s.end());
        cout << s << endl;
    }
    return 0;
}