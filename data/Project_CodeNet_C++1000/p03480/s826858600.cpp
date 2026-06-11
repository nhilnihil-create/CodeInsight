#include <bits/stdc++.h>

int solve();

int main()
{
    printf("%d\n", solve());
    return 0;
}

int solve()
{
    std::string s;
    std::cin >> s;

    int k;
    if (s.size() & 1) k = s.size() / 2 + 1;
    else k = s.size() / 2;

    for (; k < s.size(); k++)
    {
        if (s[k] != s[k - 1] || s[s.size() - k] != s[s.size() - k - 1])
            return k;
    }
    return k;
}