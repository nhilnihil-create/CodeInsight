#include<bits/stdc++.h>
using namespace std;
int main()
{
    int A,B,t,cnt=0,temp=0;
    cin>>A>>B;
    for(int i=A; i<=B; i++)
    {
        temp= i;
        t=0;
        while(temp!=0)
        {
            t=(t*10)+(temp%10);
            temp/=10;
        }
        if(A==t)
            cnt++;

            A++;
    }

    cout<<cnt<<endl;;
    return 0;
}
