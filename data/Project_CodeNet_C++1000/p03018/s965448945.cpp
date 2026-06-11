#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

int n;
char s[MAXN];

int main(){
	scanf("%s", s);
	n = strlen(s);
	
	int i = n - 1, j = 0;
	long long res = 0;
	while(i >= 0){
		if(i > 0 && s[i] == 'C' && s[i - 1] == 'B'){
			j++;
			i -= 2;
		}else{
			if(s[i] == 'A'){
				i--;
				res += j;
			}else{
				j = 0;
				i--;
			}
		}
	}
	printf("%lld\n", res);
	
	return 0;
}
