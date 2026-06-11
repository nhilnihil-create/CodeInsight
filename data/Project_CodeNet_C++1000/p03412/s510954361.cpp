/*input

*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define debug(x) cerr << (x) << '\n';
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
#define int long long
using namespace std;
const int N = 200005;
const int logN = 30;
int a[N], b[N];
int n;
vector<int> bitRep[logN];
long long cnt[logN];
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	up(i,1,n) cin >> a[i];
	up(i,1,n) cin >> b[i];

	up(i,1,n) {
		int curVal = 0;
		for(int j=0;j<logN;++j){
			if (bits(a[i], j)) curVal += (1 << j);
			bitRep[j].push_back(curVal);
		}
	}
	up(i,0,logN-1) sort(bitRep[i].begin(), bitRep[i].end());
	// up(i,0,logN-1) {
	// 	for (auto v : bitRep[i]) cout << v << ' ';
	// 	cout << '\n';
	// }
	up(i,1,n){
		// count the number of bit 0.
		int bitVal = 0;
		for(int j=0;j<logN;++j){
			cnt[j] += n;
			if (!bits(b[i], j)){
				int pos = lower_bound(bitRep[j].begin(), bitRep[j].end(), (1 << j) - bitVal) - bitRep[j].begin();
				cnt[j] -= pos;
				// cout << b[i] << " "  << i << ' ' << j << ' ' << pos <<  ' ';
				pos = lower_bound(bitRep[j].begin(), bitRep[j].end(), (1 << (j+1)) - bitVal) - bitRep[j].begin();
				// cout << pos << ' ' << '\n';
				cnt[j] -= (int)bitRep[j].size() - pos;
			}
			else {
				bitVal += (1 << j);
				int l = lower_bound(bitRep[j].begin(), bitRep[j].end(), (1 << (j+1)) - bitVal) - bitRep[j].begin(), 
				r = lower_bound(bitRep[j].begin(), bitRep[j].end(), (1 << (j+1)) + (1 << j) - bitVal) - bitRep[j].begin();	
				// cout << i << ' '  << j << ' '  << l << ' ' << r << '\n';
				cnt[j] -=  r - l;
			}
		}
	}
	int ans = 0;
	up(i,0,logN-1){
		// cout << cnt[i] << ' ';
		if (cnt[i] & 1) ans += (1 << i);
	}
	cout << ans;
}
