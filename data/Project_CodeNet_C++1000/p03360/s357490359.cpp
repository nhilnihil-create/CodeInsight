#include<bits/stdc++.h>
using namespace std;

int main()
{
	int ar[3],temp;
	int i;
	for(i=0;i<3;i++)cin>>ar[i];
		int k;
	cin>>k;
	sort(ar,ar+3);
	while(k--){
		temp=ar[2]*2;
		ar[2]=temp;

	}
	int ans=ar[0]+ar[1]+temp;
	cout<<ans<<endl;

}