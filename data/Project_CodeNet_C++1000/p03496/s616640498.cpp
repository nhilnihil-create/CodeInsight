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
#define INF 9223372036854775807

int input() {int a;cin>>a;return a;}

int n,a[50],memo,hoge;

signed main() {
    cin >> n;
    rep(i,n) {
        cin >> a[i];
        if (!i) memo = a[i], hoge = 1;
        if (abs(memo) < abs(a[i])) memo = a[i],hoge = i+1;
    }
    cout << n*2-1 << endl;
    if (memo < 0) {
        rep(i,n) cout << hoge << " " << i+1 << endl;
        for(int i=n-2;i>=0;i--) cout << i+2 << " " << i+1 << endl;
    } else {
        rep(i,n) cout << hoge << " " << i+1 << endl;
        rep11(i,n) cout << i << " " << i+1 << endl;
    }
}
