#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll m,n;
	cin>>n>>m;
	 ll left[m];
	 ll right[m];
	 for(int i=0;i<m;i++)
	 {
	 	cin>>left[i]>>right[i];
	 }
	 ll lo =left[0],hi=right[0];
	 //ll c=0;
	 for(int i=1;i<m;i++)
	 {
	 	if(hi<left[i]||lo>right[i])
	 	{	
	 		cout<<"0\n";
	 		return 0;
	 	}
	 	else
	 	{
	 	 		
	 			lo = max(left[i],lo);
	 			hi = min(right[i],hi);
	 		  
		 	
		}
	}
	cout<<hi-lo+1<<"\n"; 		
}