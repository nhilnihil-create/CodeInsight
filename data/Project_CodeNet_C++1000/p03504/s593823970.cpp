#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define repr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define invrepr(i,a,b) for(int i=b-1;i>=a;i--)
#define invrep(i,n) invrepr(i,0,n)
#define repitr(itr,a) for(auto itr=a.begin();itr!=a.end();++itr)
#define P pair<int,int>
const int MOD=998244353;
const int INF=2e9;
const double PI=acos(-1);


int main() {
    ios_base::sync_with_stdio(false);

    int n,k;
    cin >> n >> k;
    vector<int> a(100010);
    vector<vector<P>> b(k);
    rep(i,n) {
        int s,t,c;
        cin >> s >> t >> c;
        b[c-1].push_back({s,t});
    }
    rep(i,k) {
        if (b[i].size()>0) {
            sort(b[i].begin(),b[i].end());
            ++a[b[i][0].first-1];
            rep(j,b[i].size()-1) {
                if (b[i][j].second<b[i][j+1].first) {
                    --a[b[i][j].second];
                    ++a[b[i][j+1].first-1];
                }
            }
            --a[b[i][b[i].size()-1].second];
        }
    }
    int ans=0;
    rep(i,100009) {
        a[i+1]+=a[i];
        ans=max(ans,a[i+1]);
    }
    cout << ans << endl;
     
    return 0;   
}