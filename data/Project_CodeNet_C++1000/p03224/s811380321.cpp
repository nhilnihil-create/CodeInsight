#include<cstdio>

int s[500][500];

int main() {
	int n;
	scanf("%d", &n);
	int k = 1;
	while(k*(k-1) < 2*n) k++;
	if(k*(k-1) == 2*n) {
		int ind = 1;
		for(int i=0;i<k;i++) {
			s[i][i] = ind;
			for(int j=1;i+j<k-1;j++) s[i][i+j] = ind + j;
			for(int j=0;i+j+1<k;j++) s[i+j+1][i] = ind + j;
			ind += k-i-1;
		}
		printf("Yes\n");
		printf("%d\n", k);
		for(int i=0;i<k;i++) {
			printf("%d ", k-1);
			for(int j=0;j<k-1;j++) printf("%d%c", s[i][j], j==k-2 ? '\n' : ' ');
		}
	} else {
		printf("No\n");
	}
	return 0;
}
