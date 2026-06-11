#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    int a;
    set<int> ans, s;
    rep(i,4) {
        cin >> a;
        s.insert(a);
    }
    ans.insert(1);
    ans.insert(9);
    ans.insert(7);
    ans.insert(4);
    if(s == ans) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}