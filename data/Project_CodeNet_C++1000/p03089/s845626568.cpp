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
const ll INF=2e18;
const double PI=acos(-1);


int main() {
    ios_base::sync_with_stdio(false); 

    int n;
    cin >> n;
    vector<int> a(n);
    bool flag=1;
    rep(i,n) {
        cin >> a[i];
        if (a[i]>i+1) flag=0;
    }
    vector<int> ans(n);
    rep(i,n) {
        invrep(j,n-i) {
            if (a[j]==j+1) {
                ans[n-1-i]=a[j];
                a.erase(a.begin()+j);
                break;
            }
        }
    }
    if (flag) {
        rep(i,n) cout << ans[i] << endl;
    } else {
        cout << -1 << endl;
    }
    
    return 0;
}
