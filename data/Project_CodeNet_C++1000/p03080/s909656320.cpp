#include<stdio.h>
#include<algorithm>
#include<functional>
#include<cmath>
using namespace std;
long long  mod = 1000000007;
int main()
{
	int N;
	char s[110];
	scanf("%d%s", &N, &s);
	int i = 0, r = 0, b = 0;
	while (s[i] != '\0') {
		if (s[i] == 'R') {
			r++;
		}
		else if (s[i] == 'B') {
			b++;
		}
		i++;
	}
	if (r > b) {
		printf("Yes");
	}
	else {
		printf("No");
	}
	return 0;
}