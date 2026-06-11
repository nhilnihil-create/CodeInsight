#include <iostream>
#include <algorithm>
#include <utility>
#include <fstream>
#include <iomanip>
#include <complex>
#include <cmath>
#include <vector>
#include <cstring>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <queue>

#define IO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef long double ld;
const ll INF = 1e18;
const int N = 1e3 + 5, inf = 1e9, mod = 998244353;
using namespace std;

int main()
{
    IO
    int n, k, a, cnt = 0;
    vector <int> vec, ans;
    map <int, int> mp;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        cin >> a;
        if(!mp[a])
            vec.push_back(a);
        mp[a]++;
    }
    for(auto i : vec)
        ans.push_back(mp[i]);
    sort(ans.rbegin(), ans.rend());
    for(int i = k; i < ans.size(); i++)
        cnt += ans[i];
    cout << cnt << '\n';
    return 0;
}