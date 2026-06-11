#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	int N, M, X, Y;
	cin >> N >> M >> X >> Y;
	vector <int> x(N, 0);
	for (int ii = 0; ii < N; ++ii){
		cin >> x[ii];
	}
	vector <int> y(M, 0);
	for (int ii = 0; ii < M; ++ii){
		cin >> y[ii];
	}

	x.push_back(X);
	y.push_back(Y);

	sort(x.begin(), x.end());
	sort(y.begin(), y.end());

	int xmax = x[N];
	int ymin = y[0];

	if (xmax < ymin){ 
		cout << "No War" << "\n";
	} else {
		cout << "War" << "\n";		
	}


	

	return 0;
}
