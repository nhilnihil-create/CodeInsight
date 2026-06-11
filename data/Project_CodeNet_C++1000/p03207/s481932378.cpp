#include<iostream>

using namespace std;
int main ()
{
    long long int n,i,a[15],mx=0,sum=0;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]>mx)
            mx=a[i];

    }
    for(i=0;i<n;i++)
    {
        sum=sum+a[i];
    }
    cout<<(sum-(mx/2))<<endl;

}
