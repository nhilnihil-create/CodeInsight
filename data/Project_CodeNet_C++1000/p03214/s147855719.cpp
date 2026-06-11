#include<iostream>
#include<string>
#include<vector>
#include<cmath>

using namespace std;

int main(){

	int N;
	cin >> N;
	vector<int>A(N);

	double ave = 0;
	for (int i = 0; i < N; i++){
		cin >> A[i];
		ave += A[i];
	}

	ave /= (double)N;
	double sa = 100;
	int ans = 0;
	for (int i = N - 1; i >= 0; i--){
		if (sa >= abs(ave - A[i])){
			ans = i;
			sa = abs(ave - A[i]);
		}
	}

	cout << ans << endl;

	return 0;
}