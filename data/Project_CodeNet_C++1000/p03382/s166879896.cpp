#include <bits/stdc++.h>
using namespace std;

int main() {
	long n,a=0,x;
	cin>>n;
	vector<long>v(n);
	vector<long>c(n);
	for(int i=0;i<n;i++)cin>>v.at(i);
		
	
	sort(v.begin(),v.end());
	for(int i=0;i<n;i++){
		c.at(i)=2*v.at(i);
	}
	long j=0;
	while(c.at(j)<=v.at(n-1)&&j<n){
		a++;
		j++;
	}
	if(a==0){
		cout<<v.at(n-1)<<" "<<c.at(0)/2<<endl;
	}
	else{
		if(-c.at(a-1)+v.at(n-1)>c.at(a)-v.at(n-1)){
			x=c.at(a)/2;
		}
		else{
			x=c.at(a-1)/2;
		}
		cout<<v.at(n-1)<<" "<<x<<endl;
	}
	
	
	
	return 0;
}