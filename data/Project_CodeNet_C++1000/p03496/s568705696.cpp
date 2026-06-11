#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n, m) for (int i = n; i >= m; i--)

int main(){
	int n;
	int a[50];

	cin >> n;
	rep(i, n) cin >> a[i];

	auto min_it = min_element(a, a+n);
	auto max_it = max_element(a, a+n);
	int min_pos = distance(a, min_it);
	int max_pos = distance(a, max_it);
	int min = *min_it;
	int max = *max_it;

	bool mmode = false;

	int pos;
	if(abs(min) > abs(max)){
		mmode = true;
		pos = min_pos;
	}else{
		pos = max_pos;
	}

	cout << 2*n-2 << endl;

	rep(i, n) {
		if(i==pos) continue;

		cout << pos+1 << " " << i+1 << endl;
	}

	if(mmode == false){
		rep(i, n-1) cout << i+1 << " " << i+2 << endl;
	}else{
		rrep(i, n-1, 1) cout << i+1 << " " << i << endl;
	}
	
	
}
