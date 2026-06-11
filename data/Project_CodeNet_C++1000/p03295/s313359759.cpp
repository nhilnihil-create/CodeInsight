#include <iostream>
#include <string>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <list>
#include <iomanip>
#include <vector>
#include <functional>
#include <algorithm>
#include <cstdio>
#include <random>
#include <ctime>
#include <cstdlib>
#include <unordered_map>
#include <string.h>
#include <iostream>

using namespace std;
typedef long long ll;
typedef pair<int, int> Pint;
typedef pair<ll, ll> Pll;
#define rep(begin, i, end) for (int i = begin; i < (int)(end); i++)
#define all(v) v.begin(), v.end()
const int MOD = 1000000007;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<Pint> p(M);
    int a, b;
    rep(0, i, M)
    {
        cin >> a >> b;
        p.at(i) = make_pair(b, a);
    }
    sort(all(p));
    int ans = 0;
    int right = 0;
    rep(0, i, M)
    {
        if (p.at(i).second < right)
        {
            continue;
        }
        else
        {
            ans++;
            right = p.at(i).first;
        }
    }
    cout << ans << endl;
}