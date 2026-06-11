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
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    bool maki = true;
    for(int i=1;i<n;i++) if(a[i] <= a[i-1]) maki = false;
    if(maki) {
    	cout << 1 << endl;
    	return 0;
    }
    ll le = 1, ri = n, mid;
    while(ri - le > 1){
    	mid = (ri + le) / 2;
    	deque<pair<ll,ll> > dq;
    	bool ok = true;
    	for(int i=1;i<n;i++){
    		if(a[i] > a[i-1])continue;
    		else{
    			if(dq.empty()){
    				dq.push_back({a[i], 2LL});
    			}else{
    				while(!dq.empty() && dq.back().first > a[i]){
    					dq.pop_back();
    				}
    				if(dq.empty()){
    					dq.push_back({a[i], 2LL});
    				}else{
    					ll num = a[i];
    					while(!dq.empty() && dq.back().first == num && dq.back().second >= mid) dq.pop_back(), num--;
    					if(num == 0LL) ok = false;
    					if(dq.empty() || dq.back().first != num) dq.push_back({num,2LL});
    					else{
    						pair<ll,ll> p;
    						p = dq.back();
    						dq.pop_back();
    						dq.push_back({p.first, p.second+1});
    					}
    				}
    			}
    		}
    	}
    	if(ok) ri = mid;
    	else le = mid;
    }
    cout << ri << endl;
    return 0;
}
