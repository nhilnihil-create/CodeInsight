#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// 条件を見落としていませんか？
int main () {
    string N;
    cin >> N;
    ll ans = 0;
    for (auto x: N) ans += x-'0';
    cout << max((N[0]-'0'-1)+(ll)(N.size()-1)*9, ans) << endl;
}