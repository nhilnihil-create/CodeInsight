#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long int 
int lucas[100];
void cal()
{
    lucas[0]=2;
    lucas[1]=1;
    for(int i=2;i<=100;i++)
    lucas[i]=lucas[i-1]+lucas[i-2];
}
int32_t main()
{
    cal();
    int n;
    cin>>n;
    cout<<lucas[n]<<endl;
}