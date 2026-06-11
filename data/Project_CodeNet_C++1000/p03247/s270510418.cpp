#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>
#include <cstring>
 
#define sz(v) ((int)((v).size()))
#define all(v) (v).begin(), (v).end()
 
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
 
const int INF = 0x3c3c3c3c;
const ll LINF = 1ll*INF*INF*2;
 
const int MAX_N = 1001;
int n;
int x[MAX_N];
int y[MAX_N];
 
void solve(int a, int b, int x) {
	if(x==0) {
		if(a==2) {printf("RR\n"); return;}
		if(a==-2) {printf("LL\n"); return;}
		if(b==2) {printf("UU\n"); return;}
		if(b==-2) {printf("DD\n"); return;}
		if(a==0 && b==0) {printf("LR\n"); return;}
 
		if(a==1) printf("R");
		if(a==-1) printf("L");
		if(b==1) printf("U");
		if(b==-1) printf("D");
		printf("\n");
		return;
	}
 
	int d = 1<<x;
	bool t1 = (a+b)>0, t2=(a-b)>0;
 
	if(t1) {
		if(t2) {
			printf("R");
			solve(a-d, b, x-1);
		} else {
			printf("U");
			solve(a, b-d, x-1);
		}
	} else {
		if(t2) {
			printf("D");
			solve(a, b+d, x-1);
		} else {
			printf("L");
			solve(a+d, b, x-1);
		}
	}
}
 
int main(void) {
	scanf("%d", &n);
	for(int i=0; i<n; i++) scanf("%d%d", x+i, y+i);
 
	int k = !!((x[0]+y[0])%2);
 
	for(int i=1; i<n; i++) {
		int temp = !!((x[i]+y[i])%2);
		if(k != temp) {
			printf("-1");
			return 0;
		}
	}
 
	if(k) {
		printf("31\n");
		for(int i=30; i>=0; i--) printf("%d ", 1<<i);
		printf("\n");
	} else {
		printf("32\n");
		for(int i=30; i>=0; i--) printf("%d ", 1<<i);
		printf("1\n");
	}
 
	for(int i=0; i<n; i++) solve(x[i], y[i], 30);
}