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
    long long r, d, x;
    cin >> r >> d >> x;

    int cnt = 0;
    while (cnt < 10)
    {
        cout << r*x-d << endl;
        x = r*x - d;
        cnt++;
    }
}