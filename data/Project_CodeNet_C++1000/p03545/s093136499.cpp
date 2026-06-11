#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    int a, b, c, d;
    a = n / 1000;
    b = n / 100 - a * 10;
    c = n / 10 - a * 100 - b * 10;
    d = n - a * 1000 - b * 100 - c * 10;
    int op1[8] = {1, 1, 1, 1, -1, -1, -1, -1};
    int op2[8] = {1, 1, -1, -1, 1, 1, -1, -1};
    int op3[8] = {1, -1, 1, -1, 1, -1, 1, -1};
    char ans1 = '+';
    char ans2 = '+';
    char ans3 = '+';
    for (int i = 0; i < 8; ++i)
    {
        int cal = a + b * op1[i] + c * op2[i] + d * op3[i];
        if (cal == 7)
        {
            if (op1[i] == -1)
            {
                ans1 = '-';
            }
            if (op2[i] == -1)
            {
                ans2 = '-';
            }
            if (op3[i] == -1)
            {
                ans3 = '-';
            }
            break;
        }
    }
    cout << a << ans1 << b << ans2 << c << ans3 << d << "=7" << endl;
}