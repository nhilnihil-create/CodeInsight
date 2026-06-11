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

int n,m,a,b,ans[100000],memo[100000];
vector<int> v[100000];

void kr(int a) {
    rep(i,v[a].size()) {
        memo[v[a][i]]--;
        if (!memo[v[a][i]]) ans[v[a][i]] = a;
    }
    rep(i,v[a].size()) {
        if (!memo[v[a][i]]) {
            kr(v[a][i]);
        }
    }
}

signed main() {
    cin >> n >> m;
    rep(i,n+m-1) {
        cin >> a >> b;
        v[a].pb(b);
        memo[b]++;
    }
    int hoge=0;
    rep1(i,n) if (!memo[i]) hoge=i;
    kr(hoge);
    rep1(i,n) cout << ans[i] << endl;

}

