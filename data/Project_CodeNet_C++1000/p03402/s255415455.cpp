#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define ALL(A) A.begin(), A.end()

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int A, B; cin >> A >> B;

	int h = 42;
	int w = 100;
	vector<vector<char> > grid(h, vector<char>(w, '.'));
	rep (i, h){
		rep (j, w){
			if (i >= h / 2){
				grid[i][j] = '#';
			} // end if
		} // end rep
	} // end rep		
	--A, --B;
	while(A > 0){
		for (int i = h / 2 + 1; i < h; i += 2){
			for (int j = 1; j < w; j += 2){
				grid[i][j] = '.';
				--A;
				if (A == 0) break; 
			} // end if
			if (A == 0) break;
		} // endf or
	} // end while
	
	while(B > 0){
		for (int i = 1; i < h / 2; i += 2){
			for (int j = 1;j < w; j += 2){
				grid[i][j] = '#';
				--B;
				if (B == 0) break;
			} // end for
			if (B == 0) break;
		} // end for
	} // end while

	cout << h << ' ' << w << endl;
	rep (i, h){
		rep (j, w){
			cout << grid[i][j];
		} // end rep
		cout << endl;
	} // end rep
						
	return 0;
}