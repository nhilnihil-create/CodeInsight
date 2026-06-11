#include <bits/stdc++.h>
#define MOD 1000000007LL
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int n;
int fie[1001][1001];

int main(void){
	int a=1;
	for(int i=0;i<1000;i++){
		for(int j=0;j<=i;j++){
			fie[i][j]=a++;
		}
	}
	scanf("%d",&n);
	for(int i=1;i<=1000;i++){
		if(i*(i-1)==n*2){
			printf("Yes\n%d\n",i);
			for(int j=0;j<i;j++){
				printf("%d",i-1);
				int sx=0,sy=j;
				int dx=1,dy=0;
				if(j+1==i){
					dy=1;
					sy=0;
				}
				for(int k=0;k<i-1;k++){
					printf(" %d",fie[sy][sx]);
					if(sx==sy && dy==0){
						dx=0;
						dy=1;
					}
					sx+=dx;
					sy+=dy;
				}
				printf("\n");
			}
			return 0;
		}
	}
	printf("No\n");
	return 0;
}