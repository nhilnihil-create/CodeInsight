#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <iomanip>
#include <cstdio>
#include <set>
#include <map>
#include <list>
#include <cstdlib>

using namespace std;

#define mod (1e9 + 7)
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()

typedef long long ll;

void solve1()
{
    int n, k; cin >> n >> k;
    long double ans = 0;

    for(int i = 1; i <= n; i++) {
        
            int cnt = 0; 
            ll p = i;
            while (p < k)
            {
                p *= 2;
                cnt++;
            }
        
        double d = pow(0.5, cnt);
        ans += (1.0/ n)*(d);
        /*cout << i << endl;*/
    }

    

    cout << fixed << setprecision(12) << ans << endl;
}

int main()
{
    solve1();
}