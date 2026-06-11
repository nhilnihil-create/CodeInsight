#include <bits/stdc++.h>

#define lli unsigned long long int
#define REP(i,n) for(int i=0;i<n;i++)

using namespace std;

void swap(lli *a,lli *b){
	lli tmp = *a;
	*a = *b;
	*b = tmp;
}

int main(){

	lli q;
	cin>>q;
	REP(i,q){
		lli a,b;
		cin>>a>>b;
		lli target = a*b;
		lli num = sqrt(target);
		lli flagA=0,flagB=0;
		if(a>b){
			swap(&a,&b);
		}
		if( a==b || a+1 ==b){
			cout<<2*a-2<<endl;
			continue;
		}
		lli ans = num*2;
		if(num*num == target){
			ans--;
		}
		if((num+1)*num<target){
			cout<<ans-1<<endl;
		}
		else{
			cout<<ans-2<<endl;
		}
	}

	return 0;
}