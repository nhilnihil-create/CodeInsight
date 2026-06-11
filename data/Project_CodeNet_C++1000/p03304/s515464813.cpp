#include <bits/stdc++.h>
using namespace std;
int main(){
	int N, M, D; 
	cin >> N >> M >> D; 
	double ans = 2.0 * (N - D) * (M - 1) / N / N; 
	if(D == 0) ans *= 0.5; 
	cout.precision(15); 
	cout << ans << endl; 
}