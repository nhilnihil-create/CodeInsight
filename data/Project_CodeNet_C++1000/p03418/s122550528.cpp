#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<cmath>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<numeric>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;
int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};

int main()
{

    int n,k;
    cin >> n >> k;

    int p,r;
    ll ans = 0;
    for (int b=1; b<n+1; ++b)
    {
        p = n/b;
        r = n%b;
        // cout << "p: " << p << " r: " << r << endl;
        ans += p*max(0,b-1-k+1);
        ans += max(0,r-k+1);
        // cout << "ans: " << ans << endl;
    }
    
    if(k==0) ans -= n;
    cout << ans << endl;
    return 0;
}