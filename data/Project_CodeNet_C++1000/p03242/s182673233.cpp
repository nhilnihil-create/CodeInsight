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
    string str;
    cin >> str;
    for (int i = 0; i < str.length(); i++)
        if (str[i] == '1')
            str[i] = '9';
        else str[i] = '1';
    cout << str;
}