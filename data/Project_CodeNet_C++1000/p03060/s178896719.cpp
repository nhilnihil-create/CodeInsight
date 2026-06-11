#include <bits/stdc++.h>

using namespace std;

int main() {
int n,k,i,j,vl,cs; 
cin>>n;

int vc[n];
for(i=0;i<n;i++)
{
    cin>>vc[i];
}
for(i=0;i<n;i++)
{
    cin>>cs;
    vc[i]-=cs;
}
k=0;
for(i=0;i<n;i++)
{
    if(vc[i]>0)k+=vc[i];
}
cout<<k;
}