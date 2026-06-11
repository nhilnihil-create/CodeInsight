#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int h, w;
	cin>>h>>w;
	vector<string> a(h);
	for(auto &x : a){
		cin>>x;
	}
	vector<int> dx({1, -1, 0, 0});
	vector<int> dy({0, 0, 1, -1});
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			if(a[i][j] != '#')continue;
			bool flg = false;
			for(int k = 0; k < 4; k++){
				int nx = i + dx[k];
				int ny = j + dy[k];
				if(nx >= 0 && nx < h && ny >= 0 && ny < w && a[nx][ny] == '#')flg = true;
			}
			if(!flg){
				cout<<"No"<<endl;
				exit(0);
			}
		}
	}
	cout<<"Yes"<<endl;

	return 0;
}