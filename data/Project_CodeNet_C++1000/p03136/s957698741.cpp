#include<bits/stdc++.h>
using namespace std;
int main()
{
 long long n,i,j,a,b,c=0;
 cin>>n;
 long long A[n];
 for(i=0;i<n;i++)
 cin>>A[i];
 sort(A,A+n);
 for(i=0;i<n-1;i++)
 c+=A[i];
 if(A[n-1]<c) cout<<"Yes"<<endl;
 else cout<<"No"<<endl;
return 0;
}
