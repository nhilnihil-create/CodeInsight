#include <stdio.h>
     
int main() {
    int n, a, b, sum=0;
    scanf("%d %d %d", &n,&a,&b);
    for (int i=1; i <= n; i++) {
        int c = 0, t = i;
        for (int j = 0; j < 5; j++) {
          c += t % 10;
          t /= 10;
        }
		if (c >= a && c <= b) {
		sum += i;
		}
    }
      
	printf("%d",sum);
	return 0;
}