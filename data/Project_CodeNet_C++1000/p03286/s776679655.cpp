#include <algorithm>
#include <bitset>
#include <cmath>
#include <iostream>
#include <limits>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
void print(int x)
{
    switch (x) {
        case 0:
            cout << "10";
            break;
        case 1:
            cout << "11";
            break;
        case 2:
            cout << "00";
            break;
        case 3:
            cout << "01";
            break;
        default:
            break;
    }
    return;
}

using namespace std;
int main()
{
    long long n;
    cin >> n;
    string s;
    if (n == 0 | n == 1) {
        cout << n << endl;
        return 0;
    } else if (n > 0) {
        n -= 2;
        int digit;
        digit = static_cast<int>(log(3 * n + 4) / log(4));
        n -= static_cast<int>((pow(4, digit) - 4) / 3);
        cout << "1";
        while (digit != 0) {
            print(n / static_cast<int>(pow(4, digit - 1)));
            n %= static_cast<int>(pow(4, digit - 1));
            digit--;
        }
    } else if (n < 0) {
        n *= -1;
        n -= 3;
        int digit, flag = 0;
        digit = static_cast<int>(log((3 * n + 8) / 2) / log(4));
        if (n % 2 == 0) {
            n++;
            flag++;
        }
        n -= static_cast<int>((2 * pow(4, digit) - 8) / 3);
        cout << "1";
        n /= 2;
        while (digit != 0) {
            print(n / static_cast<int>(pow(4, digit - 1)));
            n %= static_cast<int>(pow(4, digit - 1));
            digit--;
        }
        if (flag == 0) {
            cout << "0";
        } else {
            cout << "1";
        }
    }
    cout << endl;
    return 0;
}