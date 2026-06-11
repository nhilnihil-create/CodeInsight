#include<bits//stdc++.h>
using namespace std;
int main()
{
    long long a,b,c,x[4];
    cin>>a>>b;
    x[0]=a+b;
    x[1]=a-b;
    x[2]=a*b;
    sort(x,x+3);
    cout<<x[2]<<endl;
}
