#include<iostream>
using namespace std;
int sumfun(int a[],int n){
	int i,sum=0;
	for(i=0;i<n;i++)
		sum+=a[i];
	return sum;
}

int max(int a[],int n){
	int f=a[0];
	for(int i=1;i<n;i++)
		if(a[i]>f)
			f=a[i];
	return f;
}

int main(){
	int N;
	cin>>N;
	int a[10]={0};
	for(int i=0;i<N;i++){
		cin>>a[i];
	}
	int sum=sumfun(a,N),Max=max(a,N);
	if(Max<sum-Max)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
	return 0;
}