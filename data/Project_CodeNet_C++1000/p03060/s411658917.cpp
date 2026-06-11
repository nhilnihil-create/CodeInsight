#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long i,j,k,n,m,s,t;
    cin>>n;
    long long c[n+3],v[n+3];
    for(i=0;i<n;i++){
        cin>>v[i];
    } s=0;
    for(i=0;i<n;i++){
        cin>>k;
        if(k<v[i]) s+=v[i]-k;
    }cout<<s;
}
