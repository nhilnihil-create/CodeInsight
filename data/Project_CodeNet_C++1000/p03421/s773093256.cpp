#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define rep11(i,n) for(int i=1;i<(int)(n);++i)
#define repo(i,o,n) for(int i=o;i<(int)(n);++i)
#define repm(i,n) for(int i=(int)(n)-1;i>=0;--i)
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sperase(v,n) (v).erase(remove(all(v), n), (v).end())
#define vdelete(v) (v).erase(unique(all(v)), (v).end())
#define pb(n) push_back(n)
#define mp make_pair
#define MOD 1000000007
#define INF LONG_LONG_MAX

int n,a,b;
bool memo[300001];
vector<int> v;

signed main() {
    cin >> n >> a >> b;
    if (n > a*b || n < a+b-1) {
        cout << -1 << endl;
        return 0;
    } else {
        int now=b,cnt=n;
        while(1) {
            rep(i,b) {
                if (i==b-1) a--;
                cnt--;
                cout << now-i << " ";
                memo[now-i] = true;
                if (a == cnt) {
                    rep1(k,n) if (!memo[k]) cout << k << " ";
                    return 0;
                }
            }
            now = min(n,now+b);
        }
    }
}
