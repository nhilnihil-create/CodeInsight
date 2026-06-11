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

int n;
vector<int> edge[300000];

int d[300000];
vector<int> q;

int main()
{
	int i, j, k, l;
	cin>>n;
	for(i=0;i<n-1;i++)
	{
		int x, y;
		scanf("%d%d", &x, &y), x--, y--;
		edge[x].push_back(y), edge[y].push_back(x);
	}
	memset(d, -1, sizeof(d));
	q.push_back(0);
	d[0]=0;
	for(i=0;i<q.size();i++)
	{
		int x=q[i];
		for(auto e : edge[x])
		{
			if(d[e] == -1)
			{
				d[e]=d[x]+1;
				q.push_back(e);
			}
		}
	}
	int s=q.back();
	q.clear();
	memset(d, -1, sizeof(d));
	q.push_back(s);
	d[s]=0;
	for(i=0;i<q.size();i++)
	{
		int x=q[i];
		for(auto e : edge[x])
		{
			if(d[e] == -1)
			{
				d[e]=d[x]+1;
				q.push_back(e);
			}
		}
	}
	int u=d[q.back()];
	if(u%3 == 1) cout<<"Second"<<endl;
	else cout<<"First"<<endl;
	return 0;
}
//*/