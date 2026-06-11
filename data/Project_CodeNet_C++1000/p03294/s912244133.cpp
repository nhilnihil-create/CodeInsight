#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,i,a,s=0;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a;
        s+=(a-1);
    }
    cout<<s<<endl;
}
