#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <functional>
#include <bitset>
#include <cmath>
#include <stack>
#include <iomanip>
#include <map>
#include <math.h>
typedef long long ll;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int MOD = 1000000007;
const ll INF = 1LL << 60;

ll GCD(ll a, ll b) { return b ? GCD(b, a%b) : a; }

int main()
{
   int N;
   cin >> N;
   vector<int> a(N);
   for(int i = 0; i < N; i++) cin >> a[i];
   sort(a.begin(),a.end());
   int ans = 0;
   int x = a[0];
   int count = 0;
    for(int i = 0; i < N; i++)
    {
        if(x == a[i]) count++;
        else
        {
            if(count != x || count > x)
            {
                if(count > x) ans += count - x;
                else ans += count;
            }
            x = a[i];
            count = 1;
        }
    }
    if(count > x) ans += count - x;
    if(count < x) ans += count;
    cout << ans << endl;
}