#include<iostream>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n,m;
	cin >> n >> m;
	int maxL = -1, minR = 1000000;
	for(int i=0; i<m; i++){
		int l,r;
		cin >> l >> r;
		maxL = max(maxL, l);
		minR = min(minR, r);
	}
	
	cout << max(minR - maxL + 1, 0);
	return 0;
}