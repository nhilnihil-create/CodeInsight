#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int cnt[400000] = {};

int main() {
	long long int N, A, B;
	cin >> N >> A >> B;
	if(A + B > N + 1 || A * B < N || max(A, B) > N){
		cout << "-1" << endl;
		return 0;
	}
	cnt[0] = B;
	for(int i = 1; i < A; i++){
		cnt[i] = (N - B) / (A - 1);
		if((N - B) % (A - 1) >= i){
			cnt[i]++;
		}
	}
	int sum = 0;
	for(int i = 0; i < A; i++){
		for(int j = sum + cnt[i]; j > sum; j--){
			if(i == A - 1 && j == sum + 1){
				cout << j << endl;
			}else{
				cout << j << " ";
			}
		}
		sum += cnt[i];
	}
	return 0;
}
