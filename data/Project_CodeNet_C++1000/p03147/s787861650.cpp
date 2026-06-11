#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0;i < (int)(n);i++)


int main(){
	int n;
	cin >> n;
	vector<int> v(n);
	vector<int> u(n+1);
	for (int i = 0; i < n;i++){
		cin >> v[i];
	}
	v.push_back(0);
	u[0] = v[0];
	for (int i = 0; i < n+1;i++){
		if (0 < i) u[i] = v[i]-v[i-1];
	}
	int ans = 0;
	for (int i = 0; i < n+1;i++){
		if (u[i] > 0) ans+=u[i];
	}
	//for (int i = 0; i < n;i++){
	//	cout << u[i] << " ";
	//}
	//cout << endl;
	cout << ans << endl;
	
	
	return 0; 
}

