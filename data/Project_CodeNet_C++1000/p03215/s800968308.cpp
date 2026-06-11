#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <queue>
#include <map>
#include <cmath>
#include <numeric>
#include <tuple>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

const long long mod = 1e9 + 7;

int main() {
    
    
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    vector<ll> kv;
    for (int i = 0; i < n; ++i)
    {
        ll c = a[i];
        for (int j = i + 1; j < n; ++j)
        {
            kv.push_back(c);
            c += a[j];
        }
        kv.push_back(c);
    }
    sort(kv.begin(), kv.end());
    ll ret = 0;
    for (int d = 63; d >= 0; --d)
    {
        ll count = 0;
        ll num = 1ll << d;
        ll next = ret + num;
        
        for (int i = 0; i < kv.size(); ++i)
        {
            if ((next & kv[i]) == next)
            {
                count++;
            }
        }
        if (count >= k)
        {
            ret += num;
        }
    }
    
    cout << ret << endl;
    
    
    return 0;
}