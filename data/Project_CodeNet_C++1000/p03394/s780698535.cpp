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

int n;
vector<int> a,b,c;

signed main() {
    rep1(i,30000) {
        if (i%2 == 0 && i%3 == 0) c.pb(i);
        else if (i%2 == 0) a.pb(i);
        else if (i%3 == 0) b.pb(i);
    }
    cin >> n;
    if (n == 3) {
        cout << "2 5 63" << endl;
        return 0;
    }
    rep(i,min(n-2-n%2, (int)a.size())) cout << a[i] << " ";
    n -= min(n-2-n%2, (int)a.size());
    rep(i,min(n-n%2, (int)b.size())) cout << b[i] << " ";
    n -= min(n-n%2, (int)b.size());
    rep(i,n) cout << c[i] << " ";
    cout << endl;

}


