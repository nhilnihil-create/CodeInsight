#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)
int main() {
    int a[100000];
    int n;
    cin >> n;
    rep(i, n) cin >> a[i];

    map<int, int> cnt;
    rep(i, n) cnt[a[i]]++;

    int ans = 0;
    for (auto p : cnt) {
        int x = p.first; //数字の種類
        int n = p.second; //その数字の個数
        if (n < x) //個数よりも数字が大きかったら
            ans += n; //その数字は全部取り除く
        else
            ans += n - x; //数字の方が個数よりも少なければ、その差の分取り除く
    }

    cout << ans << endl;
    return 0;
}