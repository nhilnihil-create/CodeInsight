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
    ll sum = 0, mi = INF;
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for(int i=0;i<n;i++){
    	cin >> a[i] >> b[i];
    	if(a[i] > b[i] && b[i] < mi) mi = b[i];
    	sum += a[i];
    }
    sum -= mi;
    cout << ((a == b)? 0: sum) << endl;
    return 0;
}
