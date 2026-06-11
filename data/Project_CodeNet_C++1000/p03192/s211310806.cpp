#include <bits/stdc++.h>
using namespace std;
string s;
int cnt;
int main()
{
    cin >> s;
    for (int i = 0; i < s.size(); i++)
        cnt += (s[i] == '2');
    printf("%d\n", cnt);
    return 0;
}