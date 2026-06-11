#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int main(){
	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++) cin >> A.at(i);
	A.push_back(0);
	long all_price = abs(A.at(0));
	for (int i = 0; i < N; i++) all_price += abs(A.at(i+1) - A.at(i));
	int pre = 0;
	for (int i = 0; i < N; i++){
		long ans = all_price - abs(A.at(i) - pre) - abs(A.at(i+1) - A.at(i)) + abs(A.at(i+1) - pre);
		cout << ans << endl;
		pre = A.at(i);
	}
}
