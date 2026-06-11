#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define repr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define invrepr(i,a,b) for(int i=b-1;i>=a;i--)
#define invrep(i,n) invrepr(i,0,n)
#define repitr(itr,a) for(auto itr=a.begin();itr!=a.end();++itr)
#define P pair<int,int>
const ll MOD=1e9+7;
const int MAX=1e5+10;
const ll INF=1e18;
const double PI=acos(-1);


int main() {
    ios_base::sync_with_stdio(false);

    int n,m;
    cin >> n >> m;
    vector<int> cnt(n+3);
    rep(i,m) {
        int l,r;
        cin >> l >> r;
        ++cnt[l];
        --cnt[r+1];
    }
    int ans=0;
    rep(i,n) {
        cnt[i+1]+=cnt[i];
        if (cnt[i+1]==m) ++ans;
    }
    cout << ans << endl;


    return 0;
}
