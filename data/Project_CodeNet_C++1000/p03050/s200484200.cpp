#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <deque>
#include <vector>
#include <queue> 
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <set>
using namespace std;
int main()
{
	long long n,ans=0;
	cin>>n;
	for (long long i=1;i<=sqrt(n)+sqrt(sqrt(n));i++)
		if (n%i==0&&n/i-1>i) ans+=n/i-1;
	cout<<ans;
}