#include <iostream>
#include <sstream>
#include <cmath>
#include <string>
#include <array>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <utility>
#include <iomanip>
#include <numeric>
#include <climits>
#include <algorithm>
#include <cstdint>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i % 2)
        {
            int cnt_temp = 0;
            for (int j = 1; j <= i; j++)
            {
                if (i % j == 0)
                    cnt_temp++;
            }
            if (cnt_temp == 8)
                cnt++;
        }
    }
    cout << cnt;
}