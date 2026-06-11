#include <iostream>
using namespace std;

int main()
{
    long long n, m;
    cin >> n >> m;
    //偶数の近傍が存在するマスしか裏のカードは存在しない

    if (n < 2 && m >= 2)
    {
        m -= 2;
    }
    else if (m < 2 && n >= 2)
    {
        n -= 2;
    }
    else
    {
        n -= 2;
        m -= 2;
    }

    cout << n * m << endl;

    return 0;
}
