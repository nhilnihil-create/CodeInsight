#include <bits/stdc++.h>
using namespace std;
int main()
	{
	long long int n,k=0,ans =0;
	cin>>n;
	vector<long long int> v(n,0);
	for (int i = 0; i < n; ++i)
	{
		cin>>v[i];
		k = v[i];
		while(k%2 == 0){
			k = k/2;
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}