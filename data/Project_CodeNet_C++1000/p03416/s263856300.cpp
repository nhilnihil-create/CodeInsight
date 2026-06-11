#include <bits/stdc++.h>
using namespace std;
bool judgePali(int num);

int main()
{
    int A, B, sum = 0;
    cin >> A >> B;
    for (int i = A; i <= B; ++i)
    {
        if (judgePali(i))
        {
            ++sum;
        }
    }
    cout << sum << endl;
}

bool judgePali(int num)
{
    int tmp = 0, remaind = 0, reverse = 0;
    tmp = num;

    while (tmp != 0)
    {
        /* 1桁ずつ数値を切り出す */
        remaind = tmp % 10;

        /* 数値を反転 */
        reverse = reverse * 10 + remaind;

        /* 次の桁へシフト */
        tmp /= 10;
    }
    if (num == reverse)
    {
        return true;
    }
    return false;
}