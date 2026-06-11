#include<iostream>
using namespace std;
int main (){
 long N,i,z;
 cin>>N>>i;
			  for(int x=N;x>=0;x--) 
			 {
			 	if(x>=i)
			 	z++;
			 	else
			 	break;
			 }	
			 cout<<z<<endl;
			 return 0; 
}