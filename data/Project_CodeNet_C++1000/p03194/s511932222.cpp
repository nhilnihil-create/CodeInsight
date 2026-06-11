#include<iostream>
#include<math.h>
using namespace std;
int main(void){
	long ans=0;
	long long n=0,i,N,P;
	cin>>N>>P;
	if(N==1){
		cout<<P<<endl;
		return 0;
	}
	for(i=1;n<P&&n>=0;i++){
		n=powl(i,N);
//		cout<<n<<" "<<i<<" "<<P<<" "<<ans<<endl;
		if(P%n==0)ans=i;
	}
	cout<<ans<<endl;
	return 0;
}
