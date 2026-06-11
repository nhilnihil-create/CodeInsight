#include<iostream>
#include<stdio.h>
using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);
	double ans = 0;
	for (int i = 0; i < N; i++) {
		double u;
		scanf("%lf", &u);
		string x;
		cin >> x;
		if (x == "JPY") ans += u;
		else ans += u * 380000;
		// cout << ans << "\n";
	}
	printf("%lf\n", ans);
	return 0;
}
