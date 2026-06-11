#include<bits/stdc++.h>
using namespace std;
int main()
{
int t,n,m,c,cnt=0;
long long sum=0;
cin>>n>>m>>c;
int v[n];
int b[m];
for(int i=0;i<m;i++)
cin>>b[i];
t=n;
for(int j=0;j<n;j++){
int a[m];
for(int i=0;i<m;i++){
cin>>a[i];
sum+=(a[i]*b[i]);}
sum+=c;
v[j]=sum;
sum=0;
}
for(int i=0;i<n;i++) {
if(v[i]>0) cnt++;
}
cout<<cnt<<endl;
return 0;
}