#include<bits/stdc++.h>
using namespace std;

#define LL long long

LL sum(LL x){
	LL res=0;
	while(x>0){
		res += (x%10);
		x/=10;
	}
	return res;
}

int main(){
	

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	LL k;
	cin>>k;

	LL x=1;
	while(k--){
		cout<<x<<endl;

		LL y=0;
		for(LL i=1;i<=1000000000000000;i*=10){
			if(y==0 || (y*sum(x+i) > (x+i)*sum(y))){
				y = x+i;
			}
		}
		x=y;
	}
}