#include <bits/stdc++.h>
using namespace std;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define INF 100000000
typedef long long ll;
 
int main(){
    ll H,W;
    cin>>H>>W;
    vector<VL> a(H,vector<ll>(W,0));
    rep(i,0,H)rep(j,0,W)cin>>a[i][j];
    ll ans=0;
	vector<ll> ys, xs, yg, xg;
	rep(i,0,H){
		rep(j,0,W){
			if(i==H-1 && j==W-1) break;
			if(a[i][j]%2==1){
				ans++;
				if(j!=W-1){
					a[i][j]--;
					a[i][j+1]++;
					ys.emplace_back(i+1);
					xs.emplace_back(j+1);
					yg.emplace_back(i+1);
					xg.emplace_back(j+2);
				}
				else{
					a[i][j]--;
					a[i+1][j]++;
					ys.emplace_back(i+1);
					xs.emplace_back(j+1);
					yg.emplace_back(i+2);
					xg.emplace_back(j+1);
				}
			}
		}
	}
	cout << ans << endl;
	rep(i,0,ans) cout<<ys[i]<<" "<<xs[i]<<" "<<yg[i]<<" "<<xg[i]<<endl;
 
	return 0;
}