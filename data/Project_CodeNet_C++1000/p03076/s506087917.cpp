#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
#define int long long
#define MOD 1000000007
typedef vector<int> vi;
typedef pair<int,int> pi;
#define inf 1e18
#define For(i,a,b) for (int i = a; i < b; i++)
#define Rep(i,a,b) for (int i = a; i <= b; i++)
#define ps(x,y) fixed << setprecision(y) << x 
#define pb push_back 
#define mp make_pair 

int maxtime(int x) {
    return (x+9) / 10 * 10;
}

int remtime(int x) {
    return maxtime(x) - x;
}
 
int32_t main()
{
    fast;
    int a, b, c, d, e, ans = 0;
    cin >> a >> b >> c >> d >> e;
    ans = maxtime(a) + maxtime(b) + maxtime(c) + maxtime(d) + maxtime(e);
    ans -= max({ remtime(a), remtime(b), remtime(c), remtime(d), remtime(e) });
    cout << ans;
    
    return 0;
}