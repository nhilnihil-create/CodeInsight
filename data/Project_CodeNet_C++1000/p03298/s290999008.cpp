#include <bits/stdc++.h>
using namespace std;
using Int = long long;
pair<string, string> func(const string &s, int x)
{
    pair<string, string> P;
    for (int i = 0; i < s.size(); i++) {
        if (x & 1) {
            P.first += s[i];
        } else {
            P.second += s[i];
        }
        x >>= 1;
    }
    return P;
}
int main()
{
    int N; cin >> N;
    string S; cin >> S;
    string s1 = S.substr(0, N), s2 = S.substr(N, N);
    reverse(begin(s2), end(s2));
    map<pair<string, string>, int> M;
    Int ans = 0;
    for (int i = 0; i < (1 << N); i++) {
        M[func(s1, i)]++;
    }
    for (int i = 0; i < (1 << N); i++) {
        ans += M[func(s2, i)];
    }
    cout << ans << '\n';
    return 0;
}
