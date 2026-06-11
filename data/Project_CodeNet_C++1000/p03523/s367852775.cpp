#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX;

int main()
{
    string s;
    cin >> s;
    cout << (regex_match(s, regex(R"(A?KIHA?BA?RA?)")) ? "YES" : "NO") << endl;
}
