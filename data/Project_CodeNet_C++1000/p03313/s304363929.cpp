#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <iomanip>

#define FOR(i, a, b) for(decltype(b) i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

using namespace std;

int main()
{
	int n;
	cin >> n;

    vector<int> a(1 << n);
    vector<int> m(1 << n);
    vector<int> t(1 << n);
    vector<int> s(1 << n);

    for (auto& i : a)
        cin >> i;
    
    REP (i, 1 << n)
    {
        t[i] = a[i];
        s[i] = i;

        if (!i)
            continue;
        
        set<pair<int, int>> b;
        b.emplace(t[i], s[i]);
        
        for (int j = 1; j <= i; j <<= 1)
        {
            int k = i & ~j;
            if (k == i)
                continue;
            b.emplace(t[k], s[k]);
        }

        auto it = b.rbegin();

        t[i] = it->first;
        s[i] = it->second;

        m[i] = max((++it)->first + t[i], m[i - 1]);
        
        cout << m[i] << endl;
    }

	return 0;
}
