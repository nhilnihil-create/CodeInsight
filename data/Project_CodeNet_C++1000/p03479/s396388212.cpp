#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long  n,m;
    cin>>n>>m;
    int l=0;
    while(n<=m)
    {
        l++;
        n=2*n;
    }
    cout<<l<<endl;
return 0;
}
