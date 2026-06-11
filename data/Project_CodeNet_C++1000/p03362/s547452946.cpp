#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int N = 55555*5+1;
	vector<int> arr(N);
	vector<int> so(0);
	for(int i = 0; i < N; i++){
		arr[i] = 1;
	}
	for(int i = 2; i < sqrt(N); i++){
		if(arr[i]){
			for(int j = 0; i * (j + 2) < N; j++){
				arr[i *(j + 2)] = 0;
			}
		}
	}
	for(int i = 2; i < N; i++){
		if(arr[i]){
			so.push_back(i);
		}
	}
//	for(int i=0; i>=0; i++) if(so.at(i) == 55547){ cout << i << endl; break; }
//	cout << so.at(so.size()-1) << endl;

	int n;
	cin >> n;
	vector<int> a(0);
	rep(i, so.size()) if(so.at(i)%5 == 1) a.push_back(so.at(i));
	rep(i, n) cout << a.at(i) << ' ';
	cout << endl;
	return 0;
}