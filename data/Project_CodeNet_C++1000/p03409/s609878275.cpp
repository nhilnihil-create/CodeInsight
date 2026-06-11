// C - 2D Plane 2N Points
#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(int)(n);++i)

int main(){
	int N; cin>>N;
	vector<vi> AB(N, vi(2)), CD(N, vi(2));
	rep(i, N) cin>>AB[i][0]>>AB[i][1];
	rep(i, N) cin>>CD[i][0]>>CD[i][1];

	sort(all(CD));
	sort(all(AB), [](vi a, vi b){ return a[1] > b[1]; });

	vi vis_r(N, false);
	rep(b, N)
		rep(r, N)
			if(!vis_r[r] && AB[r][0] < CD[b][0] && AB[r][1] < CD[b][1])
				{ vis_r[r] = true; break; }

	cout<< accumulate(all(vis_r), 0) << endl;
}
