#include <bits/stdc++.h>
#include <cmath>
#include <limits>

using namespace std;
typedef long long LL;
static long long INF = (1LL<<62);

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int H, W, D; cin >> H >> W >> D;
	map<int, pair<int,int>> M;
	for(int h=1; h<=H; h++){
		for(int w=1; w<=W; w++){
			int a; cin >> a; a--;
			pair<int, int> p = make_pair(h, w);
			M[a] = p;
		}
	}

	vector<vector<int>> A(D), SA(D);
	for(int i=0; i<D; i++){
		A[i].push_back(0);
		for(int j=0; i+D*j < H*W; j++){
			int a = i + D*j;
			int b = i + D*(j+1);
			if(b >= H*W) b = i;
			auto p1 = M[a];
			auto p2 = M[b];
			A[i].push_back( abs(p1.first - p2.first) + abs(p1.second - p2.second) );
		}
		for(int k=0; k<A[i].size(); k++){
			int sa ;
			if(k == 0){
				sa = A[i][0];
			}
			else{
				sa = SA[i][k-1]+A[i][k];
			}
			SA[i].push_back(sa);
		}
	}

	int Q; cin >> Q;
	for(int i=0; i<Q; i++){
		int l, r; cin >> l >> r;
		l--; r--;
		int d = l%D;
		printf("%d\n", SA[d][r/D]-SA[d][l/D]);
	}
	return 0;
}
