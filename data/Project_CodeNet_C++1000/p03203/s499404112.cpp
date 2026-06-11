#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define PP pair<int,int>
int H, W, N;
int ans;
vector<int> y[200010], x[200010];
int main(){
	cin >> H >> W >> N;
	ans = H;
	for(int i = 0; i < N; i++){
		int X, Y;
		cin  >> X >> Y;
		y[Y].push_back(X);
		x[X].push_back(Y);
	}
	for(int i = 1; i <= max(H, W); i++){
		sort(x[i].begin(), x[i].end());
		sort(y[i].begin(), y[i].end());
	}
	int deep = 1;
	for(int i = 1; i <= H; i++){
		auto to = lower_bound(y[deep].begin(), y[deep].end(), i);
		
		if(to != y[deep].end()){
			ans = min(*to - 1, ans);
		}
		to = lower_bound(x[i + 1].begin(), x[i + 1].end(), deep + 1);
		if(to == x[i + 1].end() || *to != deep + 1){
			deep++;
		}
	}
	cout << ans << endl;
	return 0;
}