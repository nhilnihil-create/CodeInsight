#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
const int N = 2e5 + 100;
char s[N];

int main() {
		
	scanf("%s", s + 1);
	int num = 0;
	long long ans = 0;
	int n = strlen(s + 1);
	
	for(int i = 1; i <= n; i++) {
		if(s[i] == 'W') {
			num++;
			ans += i-num;
		}
	}
	
	cout << ans << endl;
	
	return 0;	
} 