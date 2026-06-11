#include <iostream>
using namespace std;

int main() {
    long long K, A, B; cin >> K >> A >> B;
    if (B-A <= 2 || K < A-1) cout << K+1 << endl;
    else {
        long long res = A;
        K -= A-1;//ビスケットがA枚になるまで1枚ずつ増やし続ける(K回中A-1回の操作をここで消費)
        if (K % 2 == 1) ++res, --K;//残り回数が奇数だったら、あと1枚増やしておく
        res += (B-A) * (K/2);//最後に残った回数で目一杯、2手一組でB-Aを増やし続ける
        cout << res << endl;
    }
}