#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; i++)
int main()
{
    string s;
    int sum = 0;
    cin >> s;
    string sub = s;
    for (int bits = 0; bits < (1 << 4); bits++)
    {
        sum = (int)(s[0] - '0');
        sub = s;
        for (int i = 1; i < 4; i++)
        {
            if (bits & (1 << i))
            {
                sub.insert(i * 2 - 1, "+");
                sum += (int)(s[i] - '0');
            }
            else
            {

                sub.insert(i * 2 - 1, "-");
                sum -= (int)(s[i] - '0');
            }
        }
        // cout << sum << endl;
        sub.insert(sub.length(), "=7");
        if (sum == 7)
        {
            break;
        }
    }
    cout << sub << endl;
    return 0;
}
