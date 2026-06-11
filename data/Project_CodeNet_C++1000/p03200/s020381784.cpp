#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

char s[MAXN];
int n;

int main(){
	scanf("%s", s);
	n = strlen(s);
	
	int cnt = 0;
	long long sum = 0;
	
	for(int i = 0; i < n; i++){
		if(s[i] == 'B'){
			cnt++;
			sum -= i;
		}
	}
	
	for(int i = n - cnt; i < n; i++){
		sum += i;
	}
	
	printf("%lld\n", sum);
	
	return 0;
}
