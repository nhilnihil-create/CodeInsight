#include <bits/stdc++.h>

using namespace std;
const int maxn = 40;
const int base = 31337;

int n;
char niz[maxn];
map< pair<int, int>, int> s;

int main() {
	scanf("%d%s", &n, niz);
	for (int i = 0; i < (1 << n); i++) {
		int hasc = 0;
		for (int j = 0; j < n; j++) 
			if (i & (1 << j)) hasc *= base, hasc += niz[j];
		
		int hasp = 0;
		for (int j = n - 1; j >= 0; j--)
			if (!(i & (1 << j))) hasp *= base, hasp += niz[j];
		s[make_pair(hasc, hasp)]++;
	}
	
	long long sol = 0;
	for (int i = 0; i < (1 << n); i++) {
		int hasc = 0;
		for (int j = 0; j < n; j++) 
			if (i & (1 << j)) hasc *= base, hasc += niz[j + n];
		
		int hasp = 0;
		for (int j = n - 1; j >= 0; j--)
			if (!(i & (1 << j))) hasp *= base, hasp += niz[j + n];
		
		sol += s[make_pair(hasp, hasc)];
	}
	printf("%lld", sol);
	return 0;
}