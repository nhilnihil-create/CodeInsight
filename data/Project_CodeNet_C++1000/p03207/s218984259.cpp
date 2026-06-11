#include<bits/stdc++.h>
using namespace std;

int d[1000001];
int main()
{
long long n;
cin>>n;
long long a[n];
for(int i=0;i<n;i++)cin>>a[i];
cout<<accumulate(a,a+n,0ll)-*max_element(a,a+n)/2<<endl;
	


}

