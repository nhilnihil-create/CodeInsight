#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main()
{
	int k;
	vector<int>v(3);
	for(int i=0;i<3;i++)cin>>v[i];
	cin>>k;
	for(int i=0;i<k;i++)
	{
		sort(v.begin(),v.end());
		v[2]*=2;
	}
	cout<<v[0]+v[1]+v[2]<<endl;
	return 0;
}