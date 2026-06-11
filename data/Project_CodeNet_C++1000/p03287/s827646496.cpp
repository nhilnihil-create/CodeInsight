#include <iostream>
#include <algorithm>
#include <map>
#include <utility>

using namespace std;
int n, m, a[100005];
map<int, int> mp;

int main()
{
    cin >> n >> m;
    long long rj = 0, s = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        s = (s + a[i]) % m;
        if (s == 0)
            ++rj;
        if (mp.find(s) != mp.end())
            rj += mp[s];
        ++mp[s];
    }
    cout << rj << endl;
    return 0;
}