#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
ll x,n,s1=0,s2=0,s=0,i;
cin>>n;
int a[n],b[n];

for(i=0;i<n;i++){cin>>a[i];}
for(i=0;i<n;i++){cin>>b[i];s2+=b[i];}
for(i=0;i<n;i++)
{ s1+=a[i];
    s=max(s,s1+s2);
    s2-=b[i];
}cout<<s;
}