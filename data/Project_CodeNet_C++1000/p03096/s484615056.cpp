#include <iostream>
#include <map>
using namespace std;
#define N 200001
#define DD 1000000007
int a[N];
int f = 1;
map<int,int> m;
int main()
{
	int n,tot = 1;
	cin >> n;
	for(int i = 1;i <= n;i ++)
		cin >> a[i];
	for(int i = 2;i <= n;i ++)
	{
		if(a[i] != a[i - 1])
			a[++tot] = a[i];
	}
	for(int i = 1;i <= tot;i ++)
	{
		f = (f + m[a[i]]) % DD;
		m[a[i]] = f;
	}
	cout << f << endl;
	return 0;
}