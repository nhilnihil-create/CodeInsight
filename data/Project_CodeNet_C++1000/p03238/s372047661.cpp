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
    if (n == 1)
    {
        cout << "Hello World";
        return 0;
    }
    else
    {
        int a, b;
        cin >> a >> b;

        cout << a + b;
    }
}