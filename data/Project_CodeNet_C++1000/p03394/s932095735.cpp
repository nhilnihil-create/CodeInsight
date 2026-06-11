#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e4+7;
int a[N]={2,10,3,9,4,8,6,12};
int b[N]={6,2,10,3,9,4,8,12};
int main(){
	int n;
	cin>>n;
	if(n==3){
		puts("2 5 63");
		return 0;
	}
	else if(!(n&1)){
		for(int i = 8;i<n;i++) a[i]=a[i-8]+12;
		for(int i = 0;i<n;i++) printf("%d ",a[i]);
	}
	else {
		for(int i = 8;i<n;i++) b[i]=b[i-8]+12;
		for(int i = 0;i<n;i++) printf("%d ",b[i]);
	}
	return 0;
}
