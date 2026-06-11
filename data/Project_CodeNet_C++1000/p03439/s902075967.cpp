#include <cstdio>
#include <cstdlib>
#include <cstddef>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <iostream>
#include <iomanip>
#include <map>
#include <numeric>
#include <set>
#define L64 long long
#define UL64 unsigned long long
#define MOD (1000000007LL)

using namespace std;

const string g_male = "Male";
const string g_female = "Female";
const string g_vacant = "Vacant";

int main(void)
{
    int n;
    cin >> n;
    cout << 0 << endl;
    string a;
    cin >> a;
    if (a == g_vacant) {
        return 0;
    }
    int mid = n / 2;
    cout << mid << endl;
    string b;
    cin >> b;
    if (b == g_vacant) {
        return 0;
    }
    int left = 0;
    int right = n;
    bool left_is_male = true;

    if (mid % 2 == 0) {
        if (a == b) {
            left = mid;
            left_is_male = b == g_male;
        }
        else {
            right = mid;
            left_is_male = a == g_male;
        }
    }
    else {
        if (a == b) {
            right = mid;
            left_is_male = a == g_male;
        }
        else {
            left = mid;
            left_is_male = b == g_male;
        }
    }
    while (true) {
        mid = (left + right) / 2;
        cout << mid << endl;
        string c;
        cin >> c;
        if (c == g_vacant) {
            return 0;
        }
        bool mid_is_male = c == g_male;
        if ((mid - left) % 2 == 0) {
            if (left_is_male == mid_is_male) {
                left = mid;
            }
            else {
                right = mid;
            }
        }
        else {
            if (left_is_male == mid_is_male) {
                right = mid;
            }
            else {
                left = mid;
                left_is_male = mid_is_male;
            }
        }
    }

    return 0;
}
