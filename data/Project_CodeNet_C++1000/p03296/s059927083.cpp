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
    ll N;
    cin >> N;
    ll num,cnt=1;
    cin >> num;
    ll ans = 0;
    for (int i = 1; i < N; i++) {
        ll a; cin >> a;
        if(num == a){
            cnt++;
        } else {
            if(cnt != 1){
                ans += cnt / 2;
            }
            num = a;
            cnt = 1;
        }
    }
    if(cnt != 1){
        ans += cnt / 2;
    }
    cout << ans << endl;
}