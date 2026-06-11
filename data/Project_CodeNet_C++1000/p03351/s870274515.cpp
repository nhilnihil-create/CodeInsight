#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
   int x,y,z,d;
   cin>>x>>y>>z>>d;
   if(abs(x-z)<=d || (abs(x-y)<=d && abs(y-z)<=d)){
    cout<<"Yes"<<endl;
   }
   else{cout<<"No"<<endl;}
}
