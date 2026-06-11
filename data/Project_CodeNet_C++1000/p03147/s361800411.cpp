#include<bits/stdc++.h>
// Begin Header {{{
#define all(x) (x).begin(), (x).end()
#define lli long long int
#define rep(i,n) for(lli i=0; i<n; i++)
#define loop(i, j, n) for(lli i=j; i<n; i++)
#define Max(a, b) ((a) > (b) ? (a) : (b))
#define Min(a, b) ((a) < (b) ? (a) : (b))
constexpr int INF  = 0x3f3f3f3f;
const long long mod=1e9+7;
const double PI = acos(-1);
//Function
lli combi(lli n, lli r){
	if(r==0 || r==n) return 1;
	else return combi(n-1,r) + combi(n-1,r-1);
}
lli sigma1(lli n){return n*(n+1)/2;}
lli sigma2(lli s, lli n){return sigma1(n) - sigma1(s -1);}
using namespace std;
// }}} End Header

int main() {
	int n, cnt=0;
	cin >> n;
	vector<int> h(n);
	rep(i,n) cin >> h[i];
	while(1){
		bool on = false;
		int flag = 0;
		rep(i,n){
			if(h[i] > 0){
				flag++;
				if(!on) cnt++;
				h[i]--;
				on = true;
			}else on=false;
		}
		if(flag == 0) break;
	}
	cout << cnt << endl;
	return 0;
}