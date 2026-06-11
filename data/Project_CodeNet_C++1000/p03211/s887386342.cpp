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

    vector<int> numbers;
    for (int i = 0; i < str.length() - 2; i++)
    {
        string temp;
        temp += str[i];
        temp += str[i + 1];
        temp += str[i + 2];
        numbers.push_back(stoi(temp));
    }
    int min = INT_MAX;
    for (auto x : numbers)
    {
        if (abs(x - 753) < min)
            min = abs(x - 753);
    }
    cout << min;
}
