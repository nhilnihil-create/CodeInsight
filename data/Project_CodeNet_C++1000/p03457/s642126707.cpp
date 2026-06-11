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
    int n;
    cin >> n;
    bool maki = true;
    int t, x, y;
    int now = 0, nx = 0, ny = 0;
    for(int i=0;i<n;i++){
    	cin >> t >> x >> y;
    	int dis = abs(nx - x) + abs(ny - y);
    	int num = (t - now) & 1;
    	if(dis > t - now || dis % 2 != num) maki = false;
    	else {
    		now = t;
    		nx = x;
    		ny = y;
    	}
    }
    if(maki) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
