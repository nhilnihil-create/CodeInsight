#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll LINF = 1e18;
const int mod = 1e9+7;

#define pi pair<int,int>
#define pl pair<lld,lld>

#define dump(x) cout << #x << " = " << (x) << endl
#define YES(n) cout << ((n) ? "YES" : "NO"  ) << endl
#define Yes(n) cout << ((n) ? "Yes" : "No"  ) << endl
#define SANKOU(n,a,b) cout << ((n) ? (#a) : (#b) ) << endl

#define mem0(x) memset(x,0,sizeof(x))
#define fillnum(x,n) fill(begin(x),end(x),n)
#define asort(x) sort(x.begin(),x.end())
#define dsort(x,t) sort(x.begin(),x.end(),greater<t>())
#define vuniq(x) x.erase(unique(x.begin(), x.end()), x.end())

#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)

int main() {
    ll A,B,C,X,Y;
    cin >> A >> B >> C >> X >> Y;
    ll ans = 0;
    if(A+B <= C+C){
        ll cnt = min(X,Y);
        ans += (A+B) * cnt;
    } else {
        ll cnt = min(X,Y);
        ans += (C+C) * cnt;
    }
    ll bcnt = abs(X-Y);
    if(X > Y){
        ans += min(bcnt*A,bcnt*C*2);
    } else if(X < Y){
        ans += min(bcnt*B,bcnt*C*2);
    }
    cout << ans << endl;
}