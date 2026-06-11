#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int H,W,N;
int X[200010],Y[200010],inf = 1e9;
vector<vector<int>> v(200010);

int main(){
	cin >> H >> W >> N;
	for(int i=1;i<=N;i++){
		cin >> X[i] >> Y[i];
		v[Y[i]].push_back(X[i]);
	}
	for(int i=1;i<=W;i++){
		v[i].push_back(H+1); v[i].push_back(1);
		sort(v[i].begin(),v[i].end());
	}
	int ans = inf,y[W+2] = {};
	y[1] = 1;
	for(int i=1;i<=W;i++){
		for(int j=0;j<v[i].size()-1;j++){
			if(v[i][j]<=y[i] && y[i]<v[i][j+1]){
				ans =  min(ans,v[i][j+1]-1);
				break;
			}
		}
		if(i==W) continue;
		y[i+1] = H;//こういう初期化をしないと大変なことになる
		for(int j=1;j<v[i+1].size();j++){
			if(y[i]+1<v[i+1][j]){
				y[i+1] = y[i]+1;
				break;
			}else y[i] = max(v[i+1][j],y[i]);
		}
	}
	cout << ans << endl;
}