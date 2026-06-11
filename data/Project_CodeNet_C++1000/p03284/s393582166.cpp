#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <math.h>
#include <queue>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define Sort(Array) sort(Array.begin(), Array.end())
#define rev(a) reverse(a.begin(), a.end())
#define out(ans) cout << ans << endl;
const int MOD = 1000000007;
const int INF = INT_MAX;






int main() {

    int n, k;
    cin >> n >> k;

    int ans;
    if (n%k == 0) ans = 0;
    else ans = 1; 

    out(ans);

    return 0;
}




//              g++ -std=c++1z




