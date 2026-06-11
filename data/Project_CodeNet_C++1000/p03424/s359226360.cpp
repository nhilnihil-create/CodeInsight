#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)
int main()
{
    int n;
    scanf("%d", &n);
    char s[n];
    rep(i, n) cin >> s[i];
    rep(i, n) if(s[i] == 'Y') {
        cout << "Four" << endl;
        return 0;
    } 
    cout << "Three" << endl;
    return 0;
}