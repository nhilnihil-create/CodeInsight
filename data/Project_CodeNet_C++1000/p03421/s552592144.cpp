#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <utility>
 
using namespace std;
vector<int> vec;
 
int main()
{
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("input.in", "r", stdin);
	long long n, a, b;
	scanf("%lld %lld %lld", &n, &a, &b);
	if(a+b > n+1 || a*b < n) printf("-1\n");
	else if(b == 1 && a == n)
	{
		for(int i = 1;  i <= n; i++)
		{
			printf("%d", i);
			if(i < n) printf(" ");
		} printf("\n");
	}
	else if(a == 1 && b == n)
	{
		for(int i = n;  i >= 1; i--)
		{
			printf("%d", i);
			if(i > 1) printf(" ");
		} printf("\n");
	}
	else
	{  
		for(int j = b; j >= 1; j--)
			vec.push_back(j);
		int kill = n-a+1, curr = b*2;
		for(int i = n-a+2; i <= n; i++)
		{
			vec.push_back(i);
			for(int j = max(2*b-kill,1LL); j <= b-1 && kill > b; j++)
			{
				vec.push_back(curr-j);
				kill--;
			}
			curr += b-1;
		}
 
		for(int i = 0; i < vec.size(); i++)
		{
			printf("%d", vec[i]);
			if(i == vec.size()-1) printf("\n");
			else printf(" ");
		}
	}
}