#include <iostream> 
#include<vector>
#include<algorithm>
#include<map>
#include<iomanip>
#include<set>
#include<queue>
#include<deque>
#include<iomanip>
#include<sstream>
#include<cmath>
#include<bitset>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define req(i,n) for(int i = 1;i <=  n; i++)
#define rrep(i,n) for(int i = n -1;i >= 0;i--)
#define ALL(obj) begin(obj), end(obj)
typedef long long int ll;
typedef long double ld;
const ll INF = (1 << 30);
ld h, m,n, sum,d; string s, t;
const ll MOD= 1000000007;
const ld PI = acos(-1);
int main() {
    cin >> n >> m >> d;
    if (d == 0) cout << fixed << setprecision(10) << (n-d) * (m-1) / (n*n) << endl;
    else cout << fixed << setprecision(10) << 2 * (n - d) *(m - 1)/ (n * n) << endl;
    
}