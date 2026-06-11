#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)
int main()
{
    string s, t;
    cin >> s >> t;
    rep(i, s.size()){
        if(s == t) {
            printf("Yes\n");
            return 0;
        }
        else {
            char temp = s[s.size() - 1];
            s = temp + s;
            s.pop_back();
        }
    }
    printf("No\n");
    return 0;
}