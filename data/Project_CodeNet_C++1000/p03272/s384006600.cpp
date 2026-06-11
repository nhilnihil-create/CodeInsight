#include <iostream>
#include <math.h>
#include <numeric>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <tuple>
#include <functional>

#define PI 3.14159265359
#define INF 1e9
#define LINF 1e18
#define rep(i,n) for(int i = 0; i < n; i++)
#define rep2(i,a,n) for(int i = a; i < n; i++)
#define in(a) cin >> a
#define out(a) cout << a << endl

using namespace std;

typedef long long ll;
typedef pair<ll, ll> PLL;

int main() 
{
    int n,i;cin >> n >> i;
    cout << n-i+1;
    return 0;
}

