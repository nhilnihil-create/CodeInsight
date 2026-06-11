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
    int a, b;
    cin >> a >> b;

    int c = 1;
    while (c <= 3)
    {
        if ((a * b * c) % 2)
        {
            cout << "Yes";
            return 0;
        }
        c++;
    }
    cout << "No";
}