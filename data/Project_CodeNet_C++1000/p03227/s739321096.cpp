#include <bits/stdc++.h>
using namespace std;
using Int = long long;
int main()
{
    string S; cin >> S;
    if (S.size() == 3) reverse(begin(S), end(S));
    cout << S << '\n';
    return 0;
}