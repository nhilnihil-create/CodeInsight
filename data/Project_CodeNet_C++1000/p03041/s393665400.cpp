#include<bits/stdc++.h>
using namespace std;
int main(void){
int n,k;cin>>n>>k;
string s;cin>>s;
char x[n+1];
strcpy(x,s.c_str());
x[k-1]=char(int(x[k-1])+32);
string t="";
for(int i=0;i<n;i++)
    t+=x[i];
cout<<t<<endl;
return 0;}
