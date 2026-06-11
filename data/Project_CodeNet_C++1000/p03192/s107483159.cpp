#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    int n,a,b,c,d,j=0;
    cin>>n;
    a=n/1000;
    b=(n%1000)/100;
    c=(n%1000%100)/10;
    d=(n%1000%100)%10;
    if(a==2)
    j++;
    if(b==2)
    j++;
    if(c==2)
    j++;
    if(d==2)
    j++;
    cout<<j<<endl;
	return 0;
}