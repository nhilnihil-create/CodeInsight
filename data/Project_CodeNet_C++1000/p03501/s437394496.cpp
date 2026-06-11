#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, A, B;
	cin >> N >> A >> B;
	cout << min(N*A, B) << "\n";
	return 0;
}
