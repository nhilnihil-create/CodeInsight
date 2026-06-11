#include "bits/stdc++.h"

using namespace std;

#define int long long int
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define se second
#define fi first

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> matrix;

const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;

inline int add(int x, int y) { x += y; if (x >= mod) x -= mod; return x;}
inline int sub(int x, int y) { x -= y; if (x < 0) x += mod; return x;}
inline int mul(int x, int y) { return ((x % mod) * (y % mod)) % mod;}
inline int power(int a, int b) {
	int x = 1;
	while (b) {
		if (b & 1) x = mul(x, a);
		a = mul(a, a);
		b >>= 1;
	}
	return x;
}
inline int inv(int a) { return power(a, mod - 2);}

#undef int
int main() {
#define int long long int
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int h,w,n,x,y; cin>>h>>w>>n;
	int min_row[h+1];
	for(int i=0;i<h;i++) min_row[i]=w;
	min_row[h]=0;
	for(int i=0;i<n;i++){
		cin>>x>>y;
		x--; y--;
		min_row[x]=min(min_row[x],y);
	}
	int cur_col=0,ans=h;
	for(int i=1;i<=h;i++){
		if(min_row[i]<=cur_col){
			ans=i;
			break;
		}else if (min_row[i] == cur_col+1){
			cur_col = cur_col;
		} else {
			cur_col += 1;
		}
	}
	cout<<ans<<endl;

	return 0;
}


