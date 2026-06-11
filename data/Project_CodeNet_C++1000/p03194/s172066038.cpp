#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int main()
{ 
 LL p,n;
 cin>>p>>n;
 double x=1.0/p;
 LL mm=pow(n,x)+1.0;
 for(LL i=mm;i>=1;i--)
 {
 	 if(n%(LL)pow(i,p)==0)
 	 {
 	 	cout<<i<<"\n";
 	 	return 0;
	  }
 }
}