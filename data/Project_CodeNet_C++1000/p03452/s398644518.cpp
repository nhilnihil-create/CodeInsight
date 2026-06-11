#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <sstream>
#include <utility>
#include <tuple>
#define ll long long int
#define rep(i,x,y) for(int i=x;i<y;i++)
#define rel(i,x,y) for(int i=x-1;i>=y;i--)
#define all(x) x.begin(),x.end()
#define DMAX 1000000000
#define NMAX 100003
using namespace std;
vector<pair<int,int>> Range[NMAX];
int C[NMAX];

bool dfs(int x){
	rep(i,0,Range[x].size()){
		if(C[Range[x][i].first] == DMAX){
			C[Range[x][i].first] = C[x] + Range[x][i].second;
			if(!dfs(Range[x][i].first)) return false;
		}else if(C[Range[x][i].first] != C[x] + Range[x][i].second){
			return false;
		}
	}
	return true;
}

int main(){
	int N,M;
	cin >> N >> M;
	int l,r,d;
	rep(i,0,M){
		cin >> l >> r >> d;
		Range[l-1].push_back(make_pair(r-1,d));
		Range[r-1].push_back(make_pair(l-1,-d));
	}

	rep(i,0,N) C[i] = DMAX;

	rep(i,0,N){
		if(C[i] == DMAX){
			C[i] = 0;
			if(!dfs(i)){
				cout << "No" << endl;
				return 0;
			}
		}
	}
	cout << "Yes" << endl;
	return 0;
}
