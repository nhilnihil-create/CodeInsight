#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <numeric>
using namespace std;


int n, s, mv, to, t[105], v[105], z[40005];
int main() {
	int i, j=0;
	cin>>n;
	for(i=1; i<=n; i++) cin>>t[i], t[i]*=2;
	for(i=1; i<=n; i++) cin>>v[i], v[i]*=2;
	for(i=1; i<=n; i++) {
		to += t[i];
		z[j] = min(z[j], v[i]);
		for(++j; j<=to; j++) z[j] = min(z[j-1]+1, v[i]);
		j--;
	}
	for(i=j-1; i; i--) s += mv = min(z[i], mv+1);
	printf("%.9f", s/4.0);
	return 0;
}


// int N;
// vector<int> t,v;

// vector<int> define_path(){
// 	vector<int> path;
// 	int x = 0;
// 	int T = 0;

// 	for(int i=0;i<N;i++){
// 		path.push_back(min(x, v[i]));
// 		for(int j=T+1;j<T+t[i];j++){
// 			path.push_back(min(x+1,v[i]));
// 			x = min(x+1,v[i]);
// 		}
// 		T += t[i];
// 	}
// 	path.push_back(0);

// 	//cout << T+1 << " = " << path.size() << endl;

// 	x = 0;
// 	for(int i=N-1;0<=i;i--){
// 		path[T] = min(x,path[T]);
// 		for(int j=T-1;T-t[i]<=j;j--){
// 			path[j] = min(x+1,path[j]);
// 			x = min(x+1,path[j]);
// 		}
// 		T -= t[i];
// 	}

// 	return path;


// }

// int solve(){
// 	vector<int> path = define_path();

// 	//for(auto u:path) cout << u << endl;

// 	double ans = accumulate(path.begin(), path.end(),0)/4.0;

// 	printf("%.9f\n", ans);
// 	return 0;
// }

// int main(){
// 	cin >> N;
// 	t.resize(N);
// 	for(int i=0;i<N;i++){
// 		cin >> t[i];
// 		t[i] *= 2;
// 	}

// 	v.resize(N);
// 	for(int i=0;i<N;i++){
// 		cin >> v[i];
// 		v[i] *= 2;
// 	}

// 	solve();
// 	return 0;
// }