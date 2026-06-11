#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c=0;
    cin>>a>>b;
    int temp=a,t,k=a,rev=0,rem;
    t=abs(a-b)+1;
    while(t--)
    {
        while( temp != 0)
        {
            rem = temp % 10;
            rev = rev * 10 + rem;
            temp = temp / 10;
        }
        if(rev==k)
            c++;
        k=k+1;
        temp=k;
        rev=0;
    }
    cout<<c<<endl;
}
