#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, n) for (int i = 1; i <= (n); i++)
typedef long long ll;

int main() {
    string s;
    int K;
    cin >> s >> K;
    set<string> v;
    for (int i = 0; i < s.length(); i++) {
        for (int j = 1, lim = min((int)(s.length() - i), K); j <= lim; j++) {
            v.insert(s.substr(i, j));
        }
    }
    string x = *next(v.begin(), K - 1);
    cout << x << endl;
}