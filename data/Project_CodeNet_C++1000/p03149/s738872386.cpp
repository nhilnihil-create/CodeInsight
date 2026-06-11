#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a[10];
	for(int i=1;i<5;i++)
		cin>>a[i];
	sort(a+1,a+5,greater<int> ());
	swap(a[0],a[4]);
	const int cnt[10]={1,9,7,4};
	for(int i=0;i<4;i++)
		if(a[i]!=cnt[i]){
			cout<<"NO"<<endl;
			return 0; 
		}
	cout<<"YES"<<endl; 
	return 0;
}