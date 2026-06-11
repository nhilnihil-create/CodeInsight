#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define arep(x,n) for (int x: n)
using namespace std;

int main()
{
    vector<char> s(3);
    rep(i,3) cin >> s.at(i);
    int ans = 0;
    for(int i: s) {
        if(i == '1') ans++;
    }
    cout << ans << endl;
}