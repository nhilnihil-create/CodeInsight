#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e2 + 5, mod = 1e9 + 7;

int main()
{
    //ios::sync_with_stdio(false);cin.tie(nullptr);ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    int ans1 = 0, ans2 = 0;
    for (int i = 0; i < s.size(); i++)
    {
        ans1 += s[i] != '0' + i % 2;
        ans2 += s[i] == '0' + i % 2;
    }
    cout << min(ans1, ans2);
    return 0;
}