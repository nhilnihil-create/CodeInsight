//*
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <numeric>
#include <functional>
#define MOD 1000000007
#define MAX 0x3f3f3f3f
#define MAX2 0x3f3f3f3f3f3f3f3fll
#define ERR 1e-10
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#pragma warning(disable:4996)
using namespace std;

typedef long long ll;
typedef long double ldb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

int h, w, n;
int x, y;
char as[300000], bs[300000];

int a[300000], b[300000];

int main()
{
	int i, j, k, l;
	cin>>h>>w>>n;
	cin>>x>>y;
	x--, y--;
	scanf("%s%s", as, bs);
	for(k=0;k<2;k++)
	{
		for(i=0;i<n;i++)
		{
			if(k == 0 && as[i] == 'L') a[i]=-1;
			else if(k == 0 && as[i] == 'R') a[i]=1;
			else if(k == 1 && as[i] == 'U') a[i]=-1;
			else if(k == 1 && as[i] == 'D') a[i]=1;
			else a[i]=0;

			if(k == 0 && bs[i] == 'L') b[i]=-1;
			else if(k == 0 && bs[i] == 'R') b[i]=1;
			else if(k == 1 && bs[i] == 'U') b[i]=-1;
			else if(k == 1 && bs[i] == 'D') b[i]=1;
			else b[i]=0;
		}
		int u=!k?w-1:h-1;
		int tar=!k?y:x;
		int s=0, e=u;
		for(i=n-1;i>=0;i--)
		{
			if(b[i] == 1) s=max(0, s-1);
			else if(b[i] == -1) e=min(u, e+1);
			if(a[i] == 1) e--;
			else if(a[i] == -1) s++;
			if(s > e) break;
		}
		if(s <= tar && tar <= e) continue;
		else return !printf("NO\n");
	}
	printf("YES\n");
	return 0;
}
//*/