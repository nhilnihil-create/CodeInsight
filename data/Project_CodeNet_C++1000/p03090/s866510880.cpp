#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define repr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define invrepr(i,a,b) for(int i=b-1;i>=a;i--)
#define invrep(i,n) invrepr(i,0,n)
#define repitr(itr,a) for(auto itr=a.begin();itr!=a.end();++itr)
#define P pair<int,ll>
const ll MOD=998244353;
const int INF=1e9;
const double PI=acos(-1);


int main() {
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<P> a;
    if (n%2==0) {
        rep(i,n) {
            repr(j,i+1,n) {
                if (i+j+2!=n+1) a.push_back({i+1,j+1});
            }
        }
    } else {
        rep(i,n) {
            repr(j,i+1,n) {
                if (i+j+2!=n) a.push_back({i+1,j+1});
            }
        } 
    }
    int m=a.size();
    cout << m << endl;
    rep(i,m) cout << a[i].first << ' ' << a[i].second << endl;

    return 0;

}
