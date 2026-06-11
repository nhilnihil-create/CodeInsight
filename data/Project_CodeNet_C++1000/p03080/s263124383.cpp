#include <algorithm>
#include <array>
#include <cstddef>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    int count_r = 0;
    int count_b = 0;
    for (auto ch : s)
    {
        if (ch == 'R')
        {
            count_r++;
        }
        else
        {
            count_b++;
        }
    }
    cout << (count_r > count_b ? "Yes" : "No") << endl;
}
