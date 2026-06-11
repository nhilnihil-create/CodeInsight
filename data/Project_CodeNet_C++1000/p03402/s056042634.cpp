#include <cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<map>
#define maxn 200000+100
using namespace std;
typedef long long ll;
int mapp[105][105];
int main() {
	int a,b;
	cin >> a >> b;
	for(int i=1; i<=100; i++) {
		for(int j=1; j<=100; j++) {
			if(j<=50) mapp[i][j]=1;
			else mapp[i][j]=0;
		}
	}
	a--;
	b--;
	for(int i=1; i<=100&&a; i+=2) {
		for(int j=1; j<=50&&a; j+=3) {
			mapp[i][j]^=1;
			a--;
		}
	}
	for(int i=1;i<=100&&b;i+=2) {
		for(int j=52;j<=100&&b;j+=3) {
			mapp[i][j]^=1;
			b--;
		}
	}
	printf("100 100\n");
	for(int i=1;i<=100;i++) {
		for(int j=1;j<=100;j++) {
			if(mapp[i][j])  printf("#");
			else printf(".");
		}
		printf("\n");
	}
}
