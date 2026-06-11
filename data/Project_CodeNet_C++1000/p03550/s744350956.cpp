#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main(){
	int N;
	long Z, W;
	cin >> N >> Z >> W;
	vector <long> A(N);
	for (int i = 0; i < N; i++) cin >> A.at(i);
	long ans;
	if (N == 1)
		ans = abs(A.at(0) - W);
	else
		ans = max(abs(A.at(N-1) - W), abs(A.at(N-1) - A.at(N-2)));
	cout << ans << endl;
}
