#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	int p[n];
	for(int i=0; i<n; i++) cin >> p[i];
	sort(p, p+n);
	int res=0;
	for(int i=0; i<n-1; i++){
		res += p[i];
	}
	res += p[n-1]/2;
	cout << res;
	return 0;
}