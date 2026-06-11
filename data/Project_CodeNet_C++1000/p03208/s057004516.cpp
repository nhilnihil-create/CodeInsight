#include <iostream>
#include <algorithm>
#include <fstream>
#include <utility>
#include <iomanip>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#define IO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef long double ld;

using namespace std;
const ll INF = 1e18;
const int mod = 1e4, N = 1e5 + 5, inf = 1e9;

int main()
{
    IO
    int n, k, arr[N], mn = inf;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    for(int i = 0; i <= n - k; i++)
        mn = min(mn, arr[i + k - 1] - arr[i]);
    cout << mn << '\n';
    return 0;
}