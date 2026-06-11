// 20:47 - 20:51
// debug: 20:51 - 21:03
#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define lch (o << 1)
#define rch (o << 1 | 1)

typedef double db;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> pint;

const int N = (1 << 18) + 5;
const int INF = 0x3f3f3f3f;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;

int a[N];
pint b[N][2];
int ans[N];

int main(){
	ios::sync_with_stdio(0);

	int n; cin >> n;
	int m = 1 << n;
	
	for(int i=0; i<m; i++){
		cin >> a[i];
		b[i][0] = make_pair(a[i], i);
		b[i][1] = make_pair(0, -1);
		
		for(int k=0; k<n; k++){
			if(((i >> k) & 1) == 0) continue;
			int j = i ^ (1 << k);

			auto Add = [&](int v, int id){
				if(id == b[i][0].se || id == b[i][1].se) return;
				if(v >= b[i][0].fi){
					b[i][1] = b[i][0];
					b[i][0] = make_pair(v, id);
				}else if(v >= b[i][1].fi)
					b[i][1] = make_pair(v, id);
			};

			Add(b[j][0].fi, b[j][0].se);
			Add(b[j][1].fi, b[j][1].se);
		}
	}
	
	for(int i=1; i<m; i++){
		ans[i] = ans[i-1];
		if(b[i][0].se != b[i][0].se)
			ans[i] = max(ans[i], b[i][0].fi + b[i][0].fi);
		if(b[i][0].se != b[i][1].se)
			ans[i] = max(ans[i], b[i][0].fi + b[i][1].fi);
		if(b[i][1].se != b[i][0].se)
			ans[i] = max(ans[i], b[i][1].fi + b[i][0].fi);
		cout << ans[i] << endl;
	}

	return 0;
}