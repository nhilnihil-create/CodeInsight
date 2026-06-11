#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <cmath>
#define rep(i,n) for(int i=0; i<n; i++)
#define loop(i, j, n) for(int i=j; i<n; i++)
using namespace std;
int main()
{
	bool ans = true;
	int n, m, X, Y;
	cin >> n >> m >> X >> Y;
	vector<int> x(n);
	vector<int> y(m);

	rep(i,n) cin >> x[i];
	rep(i,m) cin >> y[i];

	int k = *max_element(x.begin(), x.end());
	int t = *min_element(y.begin(), y.end());

	for(int i=X+1; i<=Y; i++){
		if(k < i && t >= i){
			goto Rooped;
		}
	}
	ans = false;

Rooped:
	if(ans) cout << "No War" <<endl;
	else cout << "War" <<endl;
	return 0;
}
