#include <bits/stdc++.h>
using namespace std;
int A, B, C, X, Y;

//1秒間に処理できるfor文の回数は概ね10^8回程度
//atcoderでは2秒以内に実行を完了する必要がある
//この問題だとfor文を使えるのは一回までであると見立てが付く
int main()
{
    cin >> A >> B >> C >> X >> Y;
    int cost = A * X + B * Y;
    for (int i = 0; i <= 100000; i++)
    {
        int s = 2 * C * i + max(0, X - i) * A + max(0, Y - i) * B;
        if (s < cost)
            cost = s;
    }
    cout << cost << endl;
}
