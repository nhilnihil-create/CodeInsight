#include<bits/stdc++.h>
#define F(i,n) for(int i=0;i<n;i++)
using namespace std;
int main(){
long long n;	
cin>>n;
long long s=0;
for (long long d = 1; d*d <= n; ++d) {
  if (n % d == 0) {
  if(n/d-1>d)s+=n/d-1;
}}
	cout<<s<<'\n';
}