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
    string str;
    cin >> a >> b >> str;
    for (int i = 0; i < a; i++)
    {
        if (str[i] < '0' || str[i] > '9')
        {
            cout << "No";
            return 0;
        }
    }
    if (str[a] != '-')
    {
        cout << "No";
        return 0;
    }
    for (int i = a + 1; i < str.length(); i++)
    {
        if (str[i] < '0' || str[i] > '9')
        {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
}