#include "stdio.h"
#include "stdlib.h"
#include "iostream"
#include "math.h"
#include <string.h>
#include <stack>
#include <queue>
#include <map>
#include <string>
#include "algorithm"


using namespace std;
#define fori0(G) for(int i=0;i<G;i++)
#define fori1(G) for(int i=1;i<=G;i++)
#define forj0(G) for(int j=0;j<G;j++)
#define forj1(G) for(int j=1;j<=G;j++)
#define fork0(G) for(int k=0;k<G;k++)
#define fork1(G) for(int k=1;k<=G;k++)
int dx[] = { -1,0,1,0 ,0 }, dy[] = { 0,1,0,-1,0 };
#define nxnycon (0<=nx&&nx<h&&0<=ny&&ny<w) 

#define lo long long int

lo x[100006], v[100006], rm[100006], lm[100006];
int main() {
	
	lo n, c,vs,rt=0,lt=0;
	cin >> n>> c;

	fori1(n) {
		cin >> x[i];
		cin >> v[i];
		
	}
	vs = 0;
	fori1(n) {
		vs += v[i];
		rm[i] = max(rm[i-1], vs - 2*x[i]);
		//printf("(%d,%lld)", i, rm[i]);
	}
	vs = 0;
	for (int i = n;i >= 1;i--) {
		vs += v[i];
		rt = max(rt, vs - (c - x[i]) + rm[i - 1]);
	}
	vs = 0;
	for (int i = n;i >= 1;i--) {
		vs += v[i];
		lm[i] = max(lm[i + 1], vs -  2*(c-x[i]));
		//printf("(%d,%lld)", i, rm[i]);
	}
	vs = 0;
	fori1(n) {
		vs += v[i];
		lt = max(lt, vs -  x[i] + lm[i + 1]);
	}
	cout << max(rt,lt);
	//system("pause");

	return 0;

}
