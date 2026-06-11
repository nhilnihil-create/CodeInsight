#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define repr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define invrepr(i,a,b) for(int i=b-1;i>=a;i--)
#define invrep(i,n) invrepr(i,0,n)
#define repitr(itr,a) for(auto itr=a.begin();itr!=a.end();++itr)
#define P pair<int,int>
const int MOD=1e9+7;
const int INF=2e9;
const double PI=acos(-1);


int main() {
    ios_base::sync_with_stdio(false);

    int n,m;
    cin >> n;
    vector<int> d(n);
    rep(i,n) cin >> d[i];
    cin >> m;
    vector<int> t(m);
    rep(i,m) cin >> t[i];
    sort(d.begin(),d.end());
    sort(t.begin(),t.end());
    int j=0;
    bool flag=1;
    rep(i,m) {
        if (j==n) break;
        while (d[j]<t[i]) {
            ++j;
            if (j==n) {
                flag=0;
                break;
            }
        }
        if (j==n) break;
        if (d[j]!=t[i]) {
            flag=0;
            break;
        } else ++j;
    }
    if (flag) cout << "YES" << endl;
    else cout << "NO" << endl;
   
    return 0;  
}