#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(void){
	int N;
	cin >> N;
	int a[N];
	rep(i,N) cin >> a[i];
	sort(a,a+N,greater<int>());
	int Pa = 0, Pb = 0;
	rep(i,N){
		if (i%2==0) Pa += a[i];
		else Pb += a[i];
	}
	cout << Pa-Pb << endl;


	return 0;
}
