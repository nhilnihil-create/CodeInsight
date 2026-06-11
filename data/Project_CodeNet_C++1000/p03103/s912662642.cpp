#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,m;
	cin >> n >> m;
	vector<pair<long long,long long>> a(n);
	for(int i=0;i<n;i++)
	{
		int a1,a2;
		cin >> a1 >> a2;
		a.at(i) = make_pair(a1,a2);
	}
	sort(a.begin(),a.end());
	long long k=0,h=0;
	for(int i=0;i<n;i++)
	{
		long long f=a.at(i).first,
		          s=a.at(i).second;
		if(h+s>m)
		{
			k+=f*(m-h);
			h=m;
		}
		else
		{
			k+=f*s;
			h+=s;
		}
		if(h==m)
		{
			break;
		}
	}
	cout << k << endl;
	return 0;
}
