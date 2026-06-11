#include <bits/stdc++.h>
using namespace std;
using lint = long long;

bool is_prime(int N) {
    if (N == 1) return false;
    for (int i = 2; i * i <= N; ++i) {
        if (N % i == 0) return false;
    }
    return true;
}

signed main(){
	int N; cin >> N;
	int counter = 0;
	for(int i = 2; i <= 55555; i++){
		if(counter == N) break;
		if(is_prime(i) && (i % 5 == 1)){
			cout << i << " ";
			counter++;
		}
	}
	cout << endl;
}
