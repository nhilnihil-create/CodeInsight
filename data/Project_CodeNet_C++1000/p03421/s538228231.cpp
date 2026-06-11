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
	int n, a, b;
	cin >> n >> a >> b;

    if ((ll)a * b < n || a + b > n + 1)
    {
        cout << -1 << endl;
        return 0;
    }

	vector<int> v(n);
    REP (i, n)
        v[i] = i + 1;
    
    int rem = a;
    auto it = v.begin();
    auto end = v.end();

    while (rem && rem < end - it)
    {
        auto tip = it + min(b, static_cast<int>(end - it) - (rem - 1));
        reverse(it, tip);
        it = tip;
        --rem;
    }
    
    REP (i, n)
        cout << (i ? " " : "") << v[i];
    cout << endl;

	return 0;
}
