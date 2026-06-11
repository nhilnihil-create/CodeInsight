#include<bits/stdc++.h>
using namespace std;

#define int long long int 
int find(int *coe,int n)
{
    if(n==0)
    return 1;
    int result=0;

    for(int i=0;i<2;i++)
    if(coe[i]<=n)
    result+=find(coe,n-coe[i]);
    return result;
}
int32_t main()
{
    int coe[2]={4,7};
    int n;
    cin>>n;
    cout<<(find(coe,n)?"Yes":"No")<<endl;
}