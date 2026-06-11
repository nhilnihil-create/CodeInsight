#include<bits/stdc++.h>
using namespace std;
bitset<2000010>f;
int n,a,sum=0;
int main(){
	cin>>n;
	f[0]=1;
	for(int i=1;i<=n;i++){
		cin>>a;
		f|=f<<a;
		sum+=a;
	}
	for(int i=(sum+1)/2;i<=sum;i++){
		if(f[i]!=0){
			cout<<i<<endl;
			break;
		}
	}
	return 0;
}