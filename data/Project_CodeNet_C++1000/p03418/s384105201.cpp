#include<bits/stdc++.h>
using namespace std;

int main(){
	long long n,k;
	cin>>n>>k;

	long long res = 0;

	for(int i = 1;i<=n;i++){
		res+=((n/i)*max((long long)0,i-k));
		//cout<<"res:"<<i<<" "<<res<<endl;
		long long t = n%i;
		 res+=(k)?max((long long)0,t - k + 1):t;
		//cout<<i<<" "<<res<<endl;
	}
	cout<<res;
}
