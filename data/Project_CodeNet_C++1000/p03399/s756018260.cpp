#include<iostream>
using namespace std;
int a,b,c,d,ans1,ans2;
int main()
{
cin>>a>>b>>c>>d;
ans1=a<b?a:b;
ans2=c<d?c:d;
cout<<ans1+ans2<<endl;
return 0;
}