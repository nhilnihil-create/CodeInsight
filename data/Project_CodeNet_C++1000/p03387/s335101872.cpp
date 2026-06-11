#include <bits/stdc++.h>
using namespace std;
long long A[3];
int main()
{
long long a,b,i,c=1,d=0,n,m,t,j;
for(i=0;i<3;i++) cin>>A[i];
sort(A,A+3);
j=A[2]*2-(A[0]+A[1]);
if(j%2==0) cout<<j/2;
else cout<<(j+3)/2;
return 0;
}
