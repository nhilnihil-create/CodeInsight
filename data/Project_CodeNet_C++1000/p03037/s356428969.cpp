#include <iostream>

using namespace std;

int main(){
	int n,m;
	cin >> n >> m;	
	int l_max = 0;
	int r_min = n;
	int ans = 0;
	
	for(int i = 0; i < m; i++){
		int l,r;
		cin >> l >> r;
		if(r < l_max) {ans = 0; break;}
		if(l > r_min) {ans = 0; break;}
		
		l_max = (l>l_max)?l:l_max;
		r_min = (r<r_min)?r:r_min;
		ans = r_min - l_max + 1;
	}
	
	cout << ans << endl;
	return 0;
	
}