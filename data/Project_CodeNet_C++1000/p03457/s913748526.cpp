#include <bits/stdc++.h>
using namespace std;
 typedef long long ll;
 
int main() {
int n;
cin>>n;
int t[200000];
int x[200000];
int y[200000];
t[0]=0;
x[0]=0;
y[0]=0;
for(int i=1;i<=n;i++)cin>>t[i]>>x[i]>>y[i];
string ans="Yes";
for(int i=1;i<=n;i++){
int a,b,c;
a=t[i]-t[i-1];
b=abs(x[i]-x[i-1]);
c=abs(y[i]-y[i-1]);
if(a<b+c || (a-b-c)%2!=0)ans="No";
}
cout<<ans<<endl;
}