#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;
const ll INF = 1001001001;
const ll MOD = 1000000007;

ll N, K, Q, ans=INF, tmp=0;
vector<ll> A;

signed main(){
    cin >> N >> K >> Q;
    for(int i=0;i<N;i++) {
        ll a;
        cin >> a;
        A.push_back(a);
    }
    for(int i=0;i<N;i++) {
        vector<ll> v, p;
        for(int j=0;j<N;j++) {
            if(A[j]<A[i]) {
                if(v.size()>=K) {
                    sort(v.begin(), v.end());
                    for(int l=0;l<v.size()-K+1;l++) {
                        p.push_back(v[l]);
                    }
                }
                v.clear();
                continue;
            }
            v.push_back(A[j]);
        }
        if(v.size()>=K) {
            sort(v.begin(), v.end());
            for(int l=0;l<v.size()-K+1;l++) {
                p.push_back(v[l]);
            }
        }
        if(p.size()>=Q) {
            sort(p.begin(), p.end());
            ans = min(ans, p[Q-1]-p[0]);
        }
    }
    cout << ans << endl;
    return 0;
}