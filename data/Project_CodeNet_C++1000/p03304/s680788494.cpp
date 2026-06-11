#include<bits/stdc++.h>
#define rep(i,n,m) for(int i = (n); i <(m); i++)
#define rrep(i,n,m) for(int i = (n) - 1; i >=(m); i--)
#define pvec(vec) {for (auto v: vec) cout << v << ' '; cout << endl;}
#define pivec(vec) {rep(i, 0, vec.size()) cout << i << ':' << vec[i] << ' '; cout << endl;}

using namespace std;
using ll = long long;

int main()
{
    ll range, array_size, diff;
    cin >> range >> array_size >> diff;

    
    double ans = 0;
    if (diff == 0)
        ans = (double) 1/ range * (array_size - 1);
    else
        ans = (double) 2 * (range - diff) / (range * range) * (array_size - 1);

    printf("%.10f\n", ans);
    return 0;
}