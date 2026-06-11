#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a[5], min=10, store;
	for(int i=0;i<5;i++){
		cin>>a[i];
		if(a[i]%10<min && a[i]%10!=0){
			store = i;
			min=a[i]%10;
		}
	}
	int sum=0;
	for(int i=0;i<5;i++){
		if(i==store)continue;
		
		sum+=(ceil(a[i]/10.0))*10;
	}
	sum += a[store];
	cout << sum << endl;
}