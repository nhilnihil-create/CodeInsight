// https://atcoder.jp/contests/abc083/tasks/abc083_a
#include<iostream>
using namespace std;
int main()
{
    // 整数の入力
    int a,b,c,d;
    cin >> a >> b >> c >> d;

    // 出力
    // if ((a + b) > (c + d))
    // {
    //     cout << "Left";
    // }
    // else if ((a + b) < (c + d))
    // {
    //     cout << "Right";
    // }
    // else
    // {
    //     cout << "Balanced";
    // }


    string ret[3] = {"Right", "Balanced", "Left"};
    cout << ret[(((a + b) > (c + d)) - ((a + b) < (c + d))) + 1];

    return 0;
}
