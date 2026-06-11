#include<bits/stdc++.h>
using namespace std;
int main(){
	int ab,arr[5]={};
	while(cin>>ab)
		arr[ab]++;
	cout<<(count(arr,arr+5,2)==2?"YES":"NO")<<endl;
}
