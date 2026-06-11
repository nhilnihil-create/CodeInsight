#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define int ll
#define pb push_back
#define pii pair<int,int>
#define ff first
#define ss second

const int inf = 1e9;
const ll INF = 1e18;
const int MAX = 1e5+7;

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

    int a,b,q; cin>>a>>b>>q;
    set<int> sh, te;
    for(int i=0;i<a;i++){
        int x; cin>>x;
        sh.insert(x);
    }
    for(int i=0;i<b;i++){
        int x; cin>>x;
        te.insert(x);
    }
    for(int i=0;i<q;i++){
        int x; cin>>x;
        auto it = sh.lower_bound(x), it2 = te.lower_bound(x);
        pii cur1, cur2;
        cur1.ss = (it ==sh.end()) ? INF : *(it);
        cur1.ff = (it == sh.begin()) ? -INF : *(--it);
        cur2.ss = (it2 == te.end()) ? INF : *(it2);
        cur2.ff = (it2 == te.begin()) ? -INF : *(--it2);

        int ans = INF;
        ans = min(ans, max(cur1.ss,cur2.ss) - x);
        ans = min(ans, x - min(cur1.ff,cur2.ff));
        ans = min(ans, 2*(cur1.ss-x) + (x - cur2.ff));
        ans = min(ans, 2*(cur2.ss-x) + (x - cur1.ff));
        ans = min(ans, 2*(x-cur1.ff) + (cur2.ss - x));
        ans = min(ans, 2*(x-cur2.ff) + (cur1.ss - x));
        cout<<ans<<"\n";   
    }
	return 0;
}

