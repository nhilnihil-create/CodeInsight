#include<iostream>
using namespace std;
int a,b;
int main()
{
cin>>a>>b;
for(int i=1;i<=12;i++){
if(a==i)
{
if(b<i)cout<<i-1<<endl;
else cout<<i<<endl;
}
}
}