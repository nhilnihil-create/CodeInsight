#include <bits/stdc++.h>
using namespace std;
const int N = 4e6+10;
int n, a;
int sum;
bitset<N> b;
int main() {
	scanf("%d", &n);
	b[0] = 1;
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a);
		b |= b<<a;
		sum += a;
	}
	for(int i = (sum+1)/2; i <= sum; i++) {
		if(b[i] == 1) {
			printf("%d\n", i);
			return 0;
		}
	}
}