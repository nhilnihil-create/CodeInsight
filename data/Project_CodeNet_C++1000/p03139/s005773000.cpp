#include <iostream>
//#include <stdlib.h>
using namespace std;
int main(void)
{
    int N, A, B;
    cin >> N >> A >> B;
    int Min, Max;
    //最大は小さいほうが大きいほうの部分集合
    if (A < B)
        cout << A << " ";
    else
        cout << B << " ";
    //最小は共通部分のない集合、合計が全体を超えた分は共通部分
    if (A + B - N > 0)
        cout << A + B - N << endl;
    else
        cout << 0 << endl;
    return 0;
}