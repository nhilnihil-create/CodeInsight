// C - 2D Plane 2N Points
#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
#define all(x) (x).begin(),(x).end()
#define allr(x) (x).rbegin(),(x).rend()
#define rep(i,n) for(int i=0;i<(int)(n);++i)

int main(){
	int N; cin>>N;
	vvi AB(N, vi(2));
	vvi CD(N, vi(2));
	rep(i, N) cin>>AB[i][0]>>AB[i][1];
	rep(i, N) cin>>CD[i][0]>>CD[i][1];

	sort(all(CD));
	sort(allr(AB), [](vi a, vi b){ return a[1] < b[1]; });

	vvi dim_b(N, vi());
	rep(b, N)
		rep(r, N)
			if(AB[r][0] < CD[b][0] && AB[r][1] < CD[b][1])
				dim_b[b].push_back(r);

	vi vis_r(N, false);
	rep(b, N){
		// int max_ry, max_r = max_ry = -1;
		for(auto r:dim_b[b]){
			if(!vis_r[r]){ vis_r[r] = true; break; }
			// if(vis_r[r]) continue;
			// if(max_ry < AB[r][1]){
			// 	max_ry = AB[r][1];
			// 	max_r = r;
			// }
		}
		// if(max_r >= 0) vis_r[max_r] = true;
	}

	int ans = 0;
	rep(i, N) ans += vis_r[i];
	cout<< ans << endl;
}
