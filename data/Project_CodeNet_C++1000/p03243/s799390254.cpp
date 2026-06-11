#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
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

    while (1)
    {
        string temp = to_string(n);
        bool good = true;
        for (int i = 0; i < temp.length() - 1; i++)
            if (temp[i] != temp[i + 1])
                good = false;
        if (good)
        {
            cout << temp;
            return 0;
        }
        n++;
    }
}