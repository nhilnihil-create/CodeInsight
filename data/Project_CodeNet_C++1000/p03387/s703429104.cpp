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
    int a[3];
    for(int i=0;i<3;i++){
    	cin >> a[i];
    }
    sort(a,a+3);
    int ans = 0;
    if((a[2] - a[1]) & 1){
    	ans += (a[2] - a[1]) / 2;
    	a[1] = a[2] - 1;
    }else{
    	ans += (a[2] - a[1]) / 2;
    	a[1] = a[2];
    }
    if((a[2] - a[0]) & 1){
    	ans += (a[2] - a[0]) / 2;
    	a[0] = a[2] - 1;
    }else{
    	ans += (a[2] - a[0]) / 2;
    	a[0] = a[2];
    }
    sort(a, a+3);
    if(a[1] < a[2]){
    	ans++;
    }else{
    	if(a[0] < a[1]){
    		ans += 2;
    	}
    }
    cout << ans << endl;
    return 0;
}
