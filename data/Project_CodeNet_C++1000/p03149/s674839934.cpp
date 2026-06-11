#include <bits/stdc++.h>
using namespace std;
int main()
{
long long i,j,k,a,b,c=0,d,n,m,t=1,x;
long long A[4];
for(i=0;i<4;i++) cin>>A[i];
sort(A,A+4);
if(A[0]==1 && A[1]==4 && A[2]==7 && A[3]==9) cout<<"YES"<<endl;
else cout<<"NO"<<endl;
return 0;
}
