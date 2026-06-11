#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	long long p;
	double n,ans;
	cin>>n>>p;
	vector <long long > v,v1;
	for(int i=1;i*1ll*i<=p;i++)
	  {
	  	  if(i*1ll*i==p)
	  	    {
	  	    	v.push_back(i);
	  	    }
	  	  else if(p%i==0)
	  	    {
	  	    	v.push_back(i);
	  	    	v.push_back(p/i);
	  	    }
	  }
	 sort(v.begin(),v.end());
	if(n==1)
	  {
	  	cout<<p<<'\n';
	  	return 0;
	  }
	//vector <long long > v1;
	double i=1;
	while(1)
	  {	 ans=pow(i,n);
	  	 v1.push_back(ans);
	  	 if(ans>p)
	  	   {
	  	   	 break;
	  	   }
	  	 ++i;
	  }
	 
	for(int i=0;i<v1.size();i++)
	  {  
	  	 if(binary_search(v.begin(),v.end(),v1[i])==true)
	  	   ans=(i+1);
	  }
	 cout<<ans<<'\n'; 
	// your code goes here
	return 0;
}