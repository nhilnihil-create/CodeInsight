#include <bits/stdc++.h>
using namespace std;

int Min[100005];
int num[222] = {0, 6, 9, 36, 81, 216, 729, 1296, 6561, 7776, 46656, 59049};
int n;

int main(){
	for(int i = 1; i <= 100000; i++){
		Min[i] = Min[i - 1] + 1;
		for(int j = 1; j <= 11; j++){
			if(i >= num[j]) Min[i] = min(Min[i - num[j]] + 1, Min[i]);
			else break;
		}
	}
	scanf("%d", &n);
	printf("%d\n", Min[n]);
} 