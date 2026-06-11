#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, x, num, a, ans;
	cin >> n >> x;
	vector<int> vec(n);
	for (int i=0; i<n; i++){
		cin >> vec.at(i);
	}
	for (int i=0; i<n; i++){
		x-=vec.at(i);
	}
	sort(vec.begin(), vec.end());
	num=x%vec.at(0);
	a=(x-num)/vec.at(0);
	ans=a+n;
	cout << ans << endl;
}
