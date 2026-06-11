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


vector<vector<int>> enuCmb(int n, int k) {
    vector<vector<int>> res;
    if (n==0 || k==0 || n<k) {
      	return res;
    } else { 
		res=enuCmb(n-1,k);
		vector<vector<int>> res1=enuCmb(n-1,k-1);
		rep(i,res1.size()) {
			res1[i].push_back(n-1);
			res.push_back(res1[i]);
		}
		if (k==1) {
			vector<int> ins={n-1};
			res.push_back(ins);
		}
		return res;
    }
}

int main() {
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    string t="MARCH";
    vector<ll> a(5);
    rep(i,n) {
        rep(j,5) {
            if (s[i][0]==t[j]) ++a[j];
        }
    } 
    ll ans=0;
    vector<vector<int>> enu=enuCmb(5,3);
	rep(i,enu.size()) {
        ll tans=1;
		rep(j,3) tans*=a[enu[i][j]];
        ans+=tans;
	}
    cout << ans << endl;
    
    return 0;   
}