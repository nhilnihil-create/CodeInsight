#include<iostream>
using namespace std;
int rev(int n)
{
    int rem,rev=0;
     while(n)
       {
           rem=n%10;
           rev=rev*10+rem;
           n=n/10;
       }
       return rev;
}
int main()
{
    int a,b,pali=0,i,num,revnum;
    cin>>a>>b;
    for(i=a; i<=b; i++)
    {
        num=i;
        revnum=rev(num);
        if(num==revnum)
        {
            pali++;
        }
    }
    cout<<pali<<endl;
    return 0;
}
