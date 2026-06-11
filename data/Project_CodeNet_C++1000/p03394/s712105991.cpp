#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, cnt, rec;
	scanf("%d",&n);
	if (n == 3) printf("2 5 63\n");
	else if (n == 4) printf("2 5 20 63\n");
	else if (n > 15000){
		for (int i = 1; i <= 30000; i++){
			if ((i % 2 == 0 || i % 3 == 0) && i % 6 != 0) printf("%d ", i);
		}
		for (int i = 1; i <= n - 15000; i++){
			printf("%d", i * 6);
			if (i == n - 15000) printf("\n");
			else printf(" ");
		}
	}
	else{
		printf("2 4 3 9");
		n -= 4;
		rec = min(4999, n / 2);
		for (int i = 1; i <= rec; i++)
			printf(" %d %d", i * 6 + 2, i * 6 + 4);
		for (int i = rec + 1; i <= n / 2; i++)
			printf(" %d %d", (i - rec) * 12 + 3, (i - rec) * 12 + 9);
		if (n & 1) printf(" 30000\n");
		else printf("\n");
	}
	return 0;
}