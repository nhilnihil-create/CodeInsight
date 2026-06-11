#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007, INF=(1LL<<60);
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    ll a, mi = mod, ma = 0;
    for(int i=0;i<n;i++){
        cin >> a;
        mi = min(mi, a);
        ma = max(ma, a);
    }
    cout << ma - mi << endl;
    return 0;
}
