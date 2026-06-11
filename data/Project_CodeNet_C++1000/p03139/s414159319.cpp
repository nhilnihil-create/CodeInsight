#include<bits/stdc++.h>
using namespace std;
int main()
{
 long long i,j,n,a,b,c;
 cin>>n>>b>>c;
 i=min(b,c);
 j=(b+c)-n;
 if(j>0) cout<<i<<" "<<j<<endl;
 else  cout<<i<<" "<<"0"<<endl;
return 0;
}
