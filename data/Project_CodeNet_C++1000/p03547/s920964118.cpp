#include <iostream>
#include <iomanip>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <map>
#include <climits>
#include <bitset>

#define ll long long
const ll INF = 1 << 29;
const ll MOD = 1e9 + 7;

int main()
{
    char X, Y;
    std::cin >> X >> Y;
    if (X < Y)
       std::cout << "<" << std::endl;
    else if (X > Y)
        std::cout << ">" << std::endl;
    else
        std::cout << "=" << std::endl;
}