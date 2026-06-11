#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;
const int N = 2e5 + 5;

int main()
{
    int n, h, w;
    cin >> n >> h >> w;
    cout << ((n - h) + 1) * ((n - w) + 1) << endl;
}
