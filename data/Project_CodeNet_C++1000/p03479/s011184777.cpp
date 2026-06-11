#include<bits/stdc++.h>
using namespace std;
int main()
{
   long long int i,j,l,r,x,y=0;
    cin>>l>>r;
    i=r/l;
    j=log(i)/log(2);
    for(x=l;x<=r;x*=2){y++;}
    cout<<y<<endl;
    
    
    

}