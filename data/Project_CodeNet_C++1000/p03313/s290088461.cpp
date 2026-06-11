#include <iostream>
#include <vector>
#define ll long long
using namespace std;

ll a[300000], mx[300000][2], ans[300000];

int main() {
	int N;
	cin >> N;
	int m=(1<<N);
	vector<vector<int>> v(N+1);
	for(int i=0; i<m; ++i){
		cin >> a[i];
		int cnt=0;
		for(int j=0; j<N; ++j){
			if(i&(1<<j)) ++cnt;
		}
		v[cnt].push_back(i);
	}
	for(int i=0; i<v[1].size(); ++i){
		if(a[v[1][i]]<a[0]) mx[v[1][i]][1]=v[1][i];
		else mx[v[1][i]][0]=v[1][i];
	}
	for(int i=2; i<=N; ++i){
		for(int j=0; j<v[i].size(); ++j){
			if(a[v[i][j]]<a[0]) mx[v[i][j]][1]=v[i][j];
			else mx[v[i][j]][0]=v[i][j];
			for(int k=0; k<N; ++k){
				if((v[i][j])&(1<<k)){
					int g=v[i][j]-(1<<k);
					for(int p=0; p<2; ++p){
						if(a[mx[g][p]]>a[mx[v[i][j]][0]]){
							mx[v[i][j]][1]=mx[v[i][j]][0];
							mx[v[i][j]][0]=mx[g][p];
						}
						else if(mx[g][p]!=mx[v[i][j]][0] && a[mx[g][p]]>a[mx[v[i][j]][1]]){
							mx[v[i][j]][1]=mx[g][p];
						}
					}
				}
			}
		}
	}
	for(int i=1; i<m; ++i){
		ans[i]=max(ans[i-1], a[mx[i][0]]+a[mx[i][1]]);
		cout << ans[i] << endl;
	}
	return 0;
}