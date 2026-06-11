#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

struct Operation{
	int x, y, nx, ny;
	Operation(int ix = 0, int iy = 0, int inx = 0, int iny = 0){
		x = ix; y = iy; nx = inx; ny = iny;
	}
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int h, w;
	cin>>h>>w;
	int a[h][w];
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			cin>>a[i][j];
		}
	}
	vector<Operation> op;
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			if(a[i][j]&1){
				if(i + 1 < h){
					op.push_back(Operation(i + 1, j + 1, i + 2, j + 1));
					a[i + 1][j]++;
				}else if(j + 1 < w){
					op.push_back(Operation(i + 1, j + 1, i + 1, j + 2));
					a[i][j + 1]++;
				}
			}
		}
	}
	cout<<op.size()<<'\n';
	for(auto x : op){
		cout<<x.x<<" "<<x.y<<" "<<x.nx<<" "<<x.ny<<'\n';
	}

	return 0;
}