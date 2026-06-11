#include<iostream>
using namespace std;
int main()
{
    int a,b,rev,digit,count=0,x;
    cin>>a>>b;
    for(;a<=b ; )
    {
        x=a;
        rev=0;
        while(x!=0)
        {
            digit=x%10;
            rev=(rev*10)+digit;
            x=x/10;
        }
        if(a==rev)
            count++;

            a++;
    }
    cout<<count<<endl;
    return 0;
}
