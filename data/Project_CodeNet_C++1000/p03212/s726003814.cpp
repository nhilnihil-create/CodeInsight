#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
void DFS(vector<long long>& A, long long N, long long B) {
	if (B > N) return;
	long long tmp = B;
	bool th = false, fi = false, se = false;
	while (tmp != 0) {
		if (tmp % 10 == 3) th = true;
		else if (tmp % 10 == 5) fi = true;
		else if (tmp % 10 == 7) se = true;
		tmp /= 10;
	}
	if (th && fi && se) A.push_back(B);
	DFS(A, N, B * 10 + 3);
	DFS(A, N, B * 10 + 5);
	DFS(A, N, B * 10 + 7);
}
int main() {
	long long N; cin >> N;
	vector<long long>A;
	DFS(A, N, 0);
	sort(A.begin(), A.end());
	cout << A.size() << endl;
}