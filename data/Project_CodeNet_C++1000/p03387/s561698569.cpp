#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
using LLONG = long long;
const LLONG MOD = 998244353;

int main()
{
    int A, B, C; cin >> A >> B >> C;
    int sum = A + B + C;
    int M = max(A, max(B, C));
    if ((M * 3) % 2 == sum % 2)
    {
        cout << (M * 3 - sum) / 2 << endl;
    }
    else
    {
        cout << ((M + 1) * 3 - sum) / 2 << endl;
    }
}