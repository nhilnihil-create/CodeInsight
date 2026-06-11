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
    ll a[3],b[3];
    ll cnt[4];
    mem0(cnt);
    for (int i = 0; i < 3; i++) {
        cin >> a[i] >> b[i];
        cnt[a[i]-1]++;
        cnt[b[i]-1]++;
    }
    ll c[10];
    mem0(c);
    for (int i = 0; i < 4; i++) {
        c[cnt[i]]++;
    }
    YES(cnt[1] == 2 && cnt[2] == 2);
}