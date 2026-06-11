#include<bits/stdc++.h>
using namespace std;

int main()
{
    int A,B,i,count=0,len,n;
    string temp,temp2;
    cin>>A>>B;
    for(i=A; i<=B; i++)
    {
        temp=to_string(i);
        temp2=temp;
        len=temp2.length();
        n=len-1;
        for(int i=0; i<(len/2); i++)
        {

            swap(temp2[i],temp2[n]);
            n = n-1;

        }
       if(temp==temp2)
       {
           count++;
       }
    }
    cout<<count<<endl;

}