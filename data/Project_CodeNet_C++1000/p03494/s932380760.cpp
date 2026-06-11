#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, d; cin >> N;
	vector <int> A(N);
	for (int i = 0; i < N; ++i){
		int cnt = 0;
		cin >> d;
		while (d % 2 == 0){
			d /= 2;
			++cnt;
		}
		A[i] = cnt;
	}
	cout << *min_element(A.begin(),A.end()) << "\n";
	return 0;
}
