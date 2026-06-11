#include<iostream>
using namespace std;
int main(){
	int n,k;
	cin>>n>>k;
	if(n<k) cout<<"0"<<endl;
	else cout<<n-k+1<<endl;
}