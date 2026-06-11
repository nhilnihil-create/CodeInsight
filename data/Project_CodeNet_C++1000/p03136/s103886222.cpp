#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::sort;

int main()
{
    int n,sum=0;
    cin>>n;
    int a[n];
    for(int i=0;i!=n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    sort(a,a+n);
    sum-=a[n-1];

    if(a[n-1]<sum)
    {
        cout<<"Yes";
    }
    else
    {
        cout<<"No";
    }
    
    return 0;
}