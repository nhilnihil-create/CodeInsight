#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;
const ll INF = 1001001001001;

ll A, B, Q, ans=0, tmp=0;
vector<ll> As, Bs;

signed main(){
    cin >> A >> B >> Q;
    for(int i=0;i<A;i++) {
        ll a;
        cin >> a;
        As.push_back(a);
    }
    sort(As.begin(), As.end());
    for(int i=0;i<B;i++) {
        ll a;
        cin >> a;
        Bs.push_back(a);
    }
    sort(Bs.begin(), Bs.end());
    for(int i=0;i<Q;i++) {
        ll a;
        cin >> a;
        tmp = INF;
        ans = INF;
        vector<ll>::iterator itr1, itr2;
        itr1 = lower_bound(As.begin(), As.end(), a);
        itr2 = lower_bound(Bs.begin(), Bs.end(), a);
        if(itr1!=As.end()&&itr2!=Bs.end()) {
            tmp = max(*itr1-a, *itr2-a);
            ans = min(ans, tmp);
        }
        if(itr1!=As.begin()&&itr2!=Bs.end()) {
            itr1--;
            tmp = 2*min(*itr2-a, a-*itr1)+max(*itr2-a, a-*itr1);
            ans = min(tmp, ans);
        }
        itr1 = lower_bound(As.begin(), As.end(), a);
        itr2 = lower_bound(Bs.begin(), Bs.end(), a);
        if(itr1!=As.end()&&itr2!=Bs.begin()) {
            itr2--;
            tmp = 2*min(*itr1-a, a-*itr2)+max(*itr1-a, a-*itr2);
            ans = min(tmp, ans);
        }
        itr1 = lower_bound(As.begin(), As.end(), a);
        itr2 = lower_bound(Bs.begin(), Bs.end(), a);
        if(itr1!=As.begin()&&itr2!=Bs.begin()) {
            itr1--;
            itr2--;
            tmp = max(a-*itr1, a-*itr2);
            ans = min(ans, tmp);
        }
        cout << ans << endl;
    }
    return 0;
}