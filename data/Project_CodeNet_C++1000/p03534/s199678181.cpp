#include <bits/stdc++.h>
#define LL long long
using namespace std;

string s;
int cnt [3];

int main()
{
    cin >> s;
    for(int i = 0; i < s.size(); i++)
        cnt[s[i] - 'a'] ++;

    if(abs(cnt[0] - cnt[1]) > 1 || abs(cnt[0] - cnt[2]) > 1 || abs(cnt[2] - cnt[1]) > 1)
        printf("NO");
    else
        printf("YES");
    return 0;
}
