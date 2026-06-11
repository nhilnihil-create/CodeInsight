#include<bits/stdc++.h>
using namespace std;

int main ()
{
   int a,b,c,d;  cin>>a>>b>>c>>d;
   
   int s=a+b;
   int s1=c+d;
   if(s>s1){
	   cout<<"Left"<<endl;
   }
   else if(s<s1){
	   cout<<"Right"<<endl;
   }
   else if(s==s1){
	   cout<<"Balanced"<<endl;
   }


}

