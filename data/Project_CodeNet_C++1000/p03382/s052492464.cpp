#include <bits/stdc++.h>

using namespace std;

int n, A[100050];
int main(){
//	freopen("binomialcoefficients.in", "r", stdin);
	cin >> n;
	for(int i = 0; i<n; i++) cin >> A[i];
	int a = 0, b = INT_MAX;
	for(int i = 0; i<n; i++) a = max(a, A[i]);
	double poo = (double)a /2;
	for(int i = 0; i<n; i++){	
		if((double) abs((double) A[i]-poo) <= (double) abs((double) b-poo)) b = A[i];
	}
	cout << a << " " << b;
}
