#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,z,w;
	cin>>n>>z>>w;
  	vector<int> a(n);
  	for(int i=0;i<n;i++) cin>>a[i];
  	if(n==1) cout<<abs(w-a[0])<<endl;
  	else cout<<max(abs(a[n-1]-a[n-2]),abs(w-a[n-1]))<<endl;
}