#include<iostream>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<map>
#include<iomanip>
#include<sstream>
#include<vector>
#include<stack>
#include<queue>
#include<math.h>
using namespace std;

int main(){
	
	long long int m=999999999999,x=0,n,a[200005];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	cout<<a[n-1]<<" ";
	for(int i=0;i<n;i++){
		
		if(abs(a[n-1]-2*a[i])<m){
			m=abs(a[n-1]-2*a[i]);
			x=a[i];
		}
		
	}
	cout<<x;
}