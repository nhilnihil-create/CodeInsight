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
    ll ans = 0;
    vector<int> vec;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if(arr[i] < mn)
        {
            mn = arr[i];
            vec.clear();
            vec.push_back(i);
        }
        else if(arr[i] == mn)
            vec.push_back(i);
    }
    if(vec[0] + 1 < k)
        vec[0] = k - 1, ans++;
    else
    {
        ans += ceil((double) (vec[0]) / (k - 1));
        if((int)(ceil((double) (vec[0]) / (k - 1)) + 1) % k == 0)
            vec[0] = ceil((double) (vec[0]) / (k - 1)) * (k - 1) + 1;
    }
    if(vec.size() > 1)
    {
        if((n - vec.back() - 1) < k && n - k > vec[vec.size() - 2])
            vec.back() = n - k;
    }
    for (int i = 0; i < vec.size() - 1; i++)
    {
        ans += ceil(((double)vec[i + 1] - vec[i] - 1) / (k - 1));
        if(ceil(((double)vec[i + 1] - vec[i] - 1) / (k - 1)) != 0)
            vec[i + 1] = vec[i] + ceil(((double)vec[i + 1] - vec[i] - 1) / (k - 1)) * (k - 1);
    }
    ans += ceil(((double)n - vec.back() - 1) / (k - 1));
    cout << ans << '\n';
    return 0;
}