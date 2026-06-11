#include <stdio.h>
#include <algorithm>
using namespace std;

int read()
{
	char c;
	while((c = getchar()) < 48 || c > 57);
	int x = c - 48;
	while((c = getchar()) > 47 && c < 58) x = x * 10 + c - 48;
	return x;
}

int a[200002];

int main()
{		
	int n, i, x, t;
	long long s = 0;
	
	n = read();
	for(i = 1; i <= n; i++){
		a[i] = read() - i;
	}
	sort(a + 1, a + n + 1);
	x = a[(n + 1) >> 1];
	for(i = 1; i <= n; i++){
		t = a[i] - x;
		if(t < 0) t = -t;
		s += t;
	}
	printf("%lld\n", s);
				
	return 0;
}