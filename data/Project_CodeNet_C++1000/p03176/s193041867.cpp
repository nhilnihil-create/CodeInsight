#include <iostream>
#define max(a,b) a > b ? a : b
#define int long long int
#define lowbit(x) (x&-x)
using namespace std;
int bit[200005] , a[200005] , h[200005], n, mx, t;
void modify(int pos, int val){
	for(int i = pos ; i <=  n ; i += lowbit(i))
		bit[i] = max(bit[i], val);
}
int query(int pos){
	int ans = 0;
	for(int i = pos ; i > 0 ; i -= lowbit(i))
		ans = max(ans,bit[i]);
	return ans;
}
signed main(){
  	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for(int i = 0 ; i < n ; i++) cin >> h[i];
	for(int i = 0 ; i < n ; i++) cin >> a[i];
	for(int i = 0 ; i < n ; i++){
		t = query(h[i]-1);
		modify(h[i], t + a[i]);
		mx = max(mx, t + a[i]);
	}
	cout << mx << endl;
}