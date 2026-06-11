#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >>n;
    int t = 0, x = 0 , y = 0;
    string ret = "Yes";
    for (int i = 0; i < n; i++) {
        int tt, tx, ty; cin >>tt >> tx >> ty;
        // (tt - t)秒間に、(x,y) -> (tx,ty)に移動した場合かかる時間を引いたもの
        int tmp = (tt - t) - abs(tx - x) - abs(ty - y);
        if (tmp<0 || tmp%2!=0) {ret = "No"; break;} // tmp<0は時間的に到達不能、 tmp%2は時間つぶしで入れるか確認
        t = tt; x = tx; y = ty;
    }
    cout << ret << endl;
    return 0;
}