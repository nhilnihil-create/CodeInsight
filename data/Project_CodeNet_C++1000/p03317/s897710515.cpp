#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,a,i;
    cin>>n>>k;
    for(i=0;i<n;i++)
        cin>>a;
    if(n==k)
        cout<<"1"<<endl;
    else
        cout<<((n-1)%(k-1)==0?(n-1)/(k-1):(n-1)/(k-1)+1)<<endl;
}
