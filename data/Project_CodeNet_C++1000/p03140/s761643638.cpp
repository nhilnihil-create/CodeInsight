#include<bits/stdc++.h>
using namespace std;
int main()
{
 long long i,j,n,r=0;
 string a,b,c;
 cin>>n>>a>>b>>c;
 for(i=0;i<n;i++)
 {
    if(a[i]==b[i] && b[i]==c[i]) continue;
    else if(a[i]==b[i]||b[i]==c[i]||c[i]==a[i]) r++;
    else r+=2;
 }
 cout<<r<<endl;
return 0;
}
