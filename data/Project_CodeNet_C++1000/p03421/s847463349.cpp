#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007, INF=mod*mod*3LL;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int a, b, n;
    cin >> n >> a >> b;
    int memo = b, m = n;
    if(a + b > n + 1){
    	cout << -1 << endl;
    	return 0;
    }
    vector<int> ans;
    for(int i=n-a+1;i<=n;i++) ans.pb(i);
    b--;
    n -= a;
    while(n > 0){
    	if(n - a < b - 1){
    		if(n == b) while(n) ans.pb(n), n--;
    		else{
    			int num = max(1, n - a + 1);
    			int count = 1;
    			for(int i=num;i<=n;i++, count++){
    				ans.pb(i);
    				if(n - count == b){
    					while(n > 0) {
    						if(n == i) n = num - 1;
    						else ans.pb(n), n--;
    					}
    					break;
    				}
    			}
    			n -= a;
    			b--;
    		}
    	}
    	else{
    		int num = max(n - a + 1, 1);
    		for(int i=num;i<=n;i++) ans.pb(i);
    		n = num - 1; b--;
    	}
    }
    vector<int> x, y;
    for(int i=0;i<ans.size();i++){
    	int id = lower_bound(be(x), ans[i]) - x.begin();
    	if(id == x.size()) x.pb(ans[i]);
    	else x[id] = ans[i];
    	int le = -1, ri = y.size(), mid;
    	while(ri - le > 1){
    		mid = (ri + le) / 2;
    		if(y[mid] > ans[i]) le = mid;
    		else ri = mid;
    	}
    	if(ri == y.size()) y.pb(ans[i]);
    	else y[ri] = ans[i];
    }

    if(int(x.size()) != a || int(y.size()) != memo || int(ans.size()) != m) cout << -1;
    else for(auto& i: ans) cout << i << " ";
    cout << endl;
    return 0;
}
