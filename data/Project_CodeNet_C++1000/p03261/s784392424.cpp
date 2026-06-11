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
    unordered_set<string> seen;

    string str;
    cin >> str;
    seen.insert(str);
    char last = str.back();
    for (int i = 1; i < n; i++)
    {
        cin >> str;
        if (seen.find(str) != seen.end() || str[0] != last)
        {
            cout << "No";
            return 0;
        }
        seen.insert(str);
        last = str.back();
    }
    cout << "Yes";
}