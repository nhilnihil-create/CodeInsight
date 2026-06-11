#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)
int main()
{
    string s;
    cin >> s;
    int ans = 700;
    rep(i, s.size()){
        if(s[i] == 'o') ans += 100;
    }
    printf("%d\n", ans);
    return 0;
}