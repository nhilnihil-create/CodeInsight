#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> x, y, h;
	for(int i = 0; i < n; i++){
		int X, Y, H;
		cin >> X >> Y >> H;
		if(H >= 1){
			x.push_back(X);
			y.push_back(Y);
			h.push_back(H);
		}
	}
	if(x.size() == 1){
		cout << x[0] << " " << y[0] << " " << h[0] << endl;
		return 0;
	}
	for(int i = 0; i <= 100; i++){
		for(int j = 0; j <= 100; j++){
			bool check = true;
			long long H = h[0] + abs(x[0] - i) + abs(y[0] - j);
			for(int k = 1; k < x.size(); k++){
				if(h[k] >= 1){
					if(H != h[k] + abs(x[k] - i) + abs(y[k] - j)){
						check = false;
					}
				}
			}
			if(check){
				cout << i << " " << j << " " << H << endl;
				return 0;
			}
		}
	}
}
