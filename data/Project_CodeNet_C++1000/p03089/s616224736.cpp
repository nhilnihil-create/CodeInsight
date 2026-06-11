#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> ii;
#define F first
#define S second
#define sqr(x) (x)*(x)
#define pb(x) push_back(x)
#define sz(x) (int)x.size()
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define rep(i,x,y) for(int i=x;i<(y);++i)
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
/* start */

signed main(){
    IOS;
    int n; cin >> n;
    vector<int> a(n),ans;
    rep(i,0,n) cin >> a[i];
    rep(i,0,n){
        int chose=0,pos=0;
        for(int j = 0, cur = 0;j<n;++j){
            int at = j-cur+1;
            if(a[j]){
                if(a[j] == at){
                    chose=a[j];
                    pos = j;
                }
            }
            else cur++;
        }
        if(chose+pos){
            ans.pb(chose);
            a[pos]=0;
        }
        else{
            cout << "-1\n";
            return 0;
        }
    }
    reverse(all(ans));
    rep(i,0,n) cout << ans[i] << "\n";
}