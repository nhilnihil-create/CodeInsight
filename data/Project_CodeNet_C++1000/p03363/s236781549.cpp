#include <bits/stdc++.h>

#define PI 3.14159265358979323846264338327950288419

using namespace std;

int n, input;
long long sum = 0;
long long ans;

map<long long, int> M;

int main(){
	scanf("%d", &n);
	M[0LL] = 1;
	for(int i = 1; i <= n; i++){
		scanf("%d", &input);
		sum += input;
		if(M.count(sum)){
			ans += M[sum];
			M[sum]++;
		}else{
			M[sum] = 1;
		}
	}
	printf("%lld\n", ans);
	return 0;
}