#include<bits/stdc++.h>
using namespace std;

int n,sum;
long long h,w,p,q;

int main(){
	cin>>n>>h>>w;
	for(int i = 1;i <= n;i++){
		cin>>p>>q;
		if(p >= h && q >= w){
			sum++;
		}
	}
	cout<<sum<<endl;
}

