#include <bits/stdc++.h>
using namespace std;

long long hasil[100005][5];

int main () {
	int n;
	scanf("%d", &n);
	
	long long data[n + 1][5];
	for(int i = 1; i <= n; i++) {
		scanf("%lld %lld %lld", &data[i][1], &data[i][2], &data[i][3]);
	}
	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j < 4; j++) {
			for(int k = 1; k < 4; k++) {
				if(k != j) {
					if((hasil[i][j] == 0) || (hasil[i][j] < hasil[i-1][k] + data[i][j])) hasil[i][j] = hasil[i-1][k] + data[i][j];
				}
			}
		}
	}
	
	int tmp = 1;
	for(int i = 1; i < 4; i++) {
		if(hasil[n][i] > hasil[n][tmp]) tmp = i;
	}
	swap(hasil[n][1], hasil[n][tmp]);
	printf("%lld\n", hasil[n][1]);
}
