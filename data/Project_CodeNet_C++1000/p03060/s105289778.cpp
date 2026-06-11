#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int n;
	cin>>n;
	vector<int>c(n),v(n);
	for(int i=0; i<n; i++)
	 cin>>v[i];
	for(int i=0; i<n; i++)
	 cin>>c[i];
	int ans=-1e9;
	for(int i=0; i<(1<<n); i++)
	{
		int temp1=0,temp2=0;
		for(int j=0; j<n; j++){
			if(i&(1<<j)){
				temp1+=v[j];
				temp2+=c[j];
			}
		}
		ans=max(ans,temp1-temp2);
	}
	cout<<ans;
	return 0;
	
	
}