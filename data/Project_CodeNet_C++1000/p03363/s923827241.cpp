#include <bits/stdc++.h>
using namespace std;

int n, ai;

int main(){
	scanf("%d", &n);
	
	long long res = 0, sum = 0;
	
	map <long long, int> cnt;
	cnt[0]++;
	
	for(int i = 0; i < n; i++){
		scanf("%d", &ai);
		sum += ai;
		res += cnt[sum];
		cnt[sum]++;
	}
	printf("%lld\n", res);
	
    return 0;
}
