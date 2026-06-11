#include <bits/stdc++.h>
 
using namespace std;
 
 
 
int main() {
   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
     
    int a,b,i;
    cin>>a>>b;
    for(i=1;i<=3;++i)
     {
         if((a*b*i)%2==1)
           break;
     }
     
     if(i==4)
        cout<<"No";
        
     else
       cout<<"Yes";
    
    
	return 0;
	
} 