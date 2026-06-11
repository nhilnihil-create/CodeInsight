// https://atcoder.jp/contests/abc083/tasks/abc083_a
#include<iostream>
using namespace std;
int main()
{
    // 整数の入力
    unsigned long x, y;
    cin >> x >> y;

    int ct = 0;

    while (1)
    {
        if ((x > y) || (x > 10e18)) {
            break;
        }
        x *= 2;
        ct++;
    }
    
    cout << ct;

    return 0;
}
