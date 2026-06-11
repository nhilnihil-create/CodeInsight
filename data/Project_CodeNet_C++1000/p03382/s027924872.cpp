#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <sstream>
#include <queue>
#include <deque>
#define LL long long
#define MP make_pair
#define PII pair<int, int>
#define F first
#define S second
using namespace std;
int n;
LL a[100010];
int res=0;
int t;
int main()
{
	cin >>n;
	for (int i=0;i<n;i++) cin >>a[i];
	sort(a,a+n);
	t=(a[n-1]+1)/2;
	for (int i=0;i<n-1;i++)
	{
		if (abs(t-a[i])<abs(t-a[res]))
		    res=i;
	}
	cout <<a[n-1]<<" "<<a[res];
	return 0;
}