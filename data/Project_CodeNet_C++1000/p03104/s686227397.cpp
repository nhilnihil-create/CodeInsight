#include <bits/stdc++.h>
#include <math.h>

using namespace std;

long long inf=1000000007;


int main(){
	long long a,b;
	cin>>a>>b;
	a--;

	if(a%2==0){
		if((a/2)%2==0) a^=0;
		else a^=1;
	}else{
		if(((a+1)/2)%2==0) a=0;
		else a=1;
	}

	if(b%2==0){
		if((b/2)%2==0) b^=0;
		else b^=1;
	}else{
		if(((b+1)/2)%2==0) b=0;
		else b=1;
	}

	cout<<(a^b)<<endl;

	return 0;
}
