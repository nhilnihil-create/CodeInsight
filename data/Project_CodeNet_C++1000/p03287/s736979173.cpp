#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;
const ll INF = 1001001001;

ll N, M, ans=0, tmp=0;
vector<ll> A;
map<ll,ll> MP1, MP2;

signed main(){
    cin >> N >> M;
    MP1[0]++;
    for(int i=0;i<N;i++) {
        ll a;
        cin >> a;
        tmp += a;
        tmp %= M;
        MP1[tmp]++;
    }
    for(map<ll,ll>::iterator itr=MP1.begin();itr!=MP1.end();itr++) {
        pair<ll,ll> p = *itr;
        MP2[p.second]++;
    }
    
    for(map<ll,ll>::iterator itr=MP2.begin();itr!=MP2.end();itr++) {
        pair<ll,ll> p = *itr;
        if(p.first>=2) {
            ans += p.second*p.first*(p.first-1)/2;
        }
    }

    cout << ans << endl;
    return 0;
}