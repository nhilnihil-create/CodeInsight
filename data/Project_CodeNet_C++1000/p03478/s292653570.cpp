#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);	
	int N, A, B, sum = 0;
	cin >> N >> A >> B;
	for (int i = 1; i <= N; ++i){
		int digits = 0, number = i;
		while (number != 0){
			digits += number % 10;
			number /= 10;	
		}
		if (digits <= B && digits >= A) sum += i;
	}
	cout << sum << "\n";
	return 0;
}
