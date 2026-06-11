// https://atcoder.jp/contests/abc114/tasks/abc114_b

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;

    int ans = 1000;
    int curr = stoi(s.substr(0, 2));
    for (int i = 2; i < s.size(); i++)
    {
        curr = (curr % 100) * 10 + (s[i] - '0');
        ans = min(ans, abs(753 - curr));
    }

    cout << ans << endl;
    return 0;
}
