#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
int main()
{
    string s;
    cin >> s;

    int cnt = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'x') cnt++;
    }

    if (cnt <= 7) puts("YES\n");
    else puts("NO\n");
    return 0;
}