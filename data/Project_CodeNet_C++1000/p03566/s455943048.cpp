#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <numeric>
using namespace std;

int N;
vector<int> t,v;

vector<int> define_path(){
	vector<int> path(accumulate(t.begin(),t.end(),1));
	int x = 0;
	int T = 0;

	for(int i=0;i<N;i++){
		path[T] = min(x, v[i]);
		for(int j=T+1;j<=T+t[i];j++){
			path[j] = min(x+1,v[i]);
			x = min(x+1,v[i]);
		}
		T += t[i];
	}


	//cout << T+1 << " = " << path.size() << endl;

	x = 0;
	for(int i=N-1;0<=i;i--){
		path[T] = min(x,path[T]);
		for(int j=T-1;T-t[i]<=j;j--){
			path[j] = min(x+1,path[j]);
			x = min(x+1,path[j]);
		}
		T -= t[i];
	}

	return path;


}

int solve(){
	vector<int> path = define_path();

	//for(auto u:path) cout << u << endl;

	double ans = accumulate(path.begin(), path.end(),0)/4.0;

	printf("%.9f\n", ans);
	return 0;
}

int main(){
	cin >> N;
	t.resize(N);
	for(int i=0;i<N;i++){
		cin >> t[i];
		t[i] *= 2;
	}

	v.resize(N);
	for(int i=0;i<N;i++){
		cin >> v[i];
		v[i] *= 2;
	}

	solve();
	return 0;
}