#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
 
int main() {
	long long N,M,X,num1,num2,ans;
	cin>>N>>M>>X;
  num1=0;
	num2=0;
	rep(i,M){
	  long long A;
		cin>>A;
		if(A<X)num1++;
		else num2++;
	}
	ans=min(num1,num2);
	cout<<ans<<endl;
}