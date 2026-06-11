#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int a, b, sum, mul, sub;
    cin>>a>>b;

    sum=a+b;
    mul=a*b;
    sub=a-b;

    if(sum>=mul && sum>=sub) cout<<sum<<endl;
    else if(mul>=sum && mul>=sub) cout<<mul<<endl;
    else if(sub>=sum && sub>=mul) cout<<sub<<endl;


    return 0;
}

