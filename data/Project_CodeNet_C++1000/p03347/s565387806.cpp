#include <iostream>
#include <vector>
using namespace std;
int main(){
	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++){
		cin >> A[i];
	}
	bool ok = true;
	if (A[0] != 0){
		ok = false;
	}
	for (int i = 1; i < N; i++){
		if (A[i] > A[i - 1] + 1){
			ok = false;
		}
	}
	if (!ok){
		cout << -1 << endl;
	} else {
		long long sum = 0;
		for (int i = 1; i < N; i++){
			if (A[i] == A[i - 1] + 1){
				sum++;
			} else {
				sum += A[i];
			}
		}
		cout << sum << endl;
	}
}