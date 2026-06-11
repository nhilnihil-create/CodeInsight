#include<bits/stdc++.h>
using namespace std;
int main()
{
 long long i,n,j,k,c=0;
 cin>>n;
 long long A[n],B[n];
 for(i=0;i<n;i++)
 cin>>A[i];
 for(i=0;i<n;i++)
 cin>>B[i];
for(i=0;i<n;i++)
  if(A[i]-B[i]>0) c+=(A[i]-B[i]);

cout<<c<<endl;
    return 0;
}
