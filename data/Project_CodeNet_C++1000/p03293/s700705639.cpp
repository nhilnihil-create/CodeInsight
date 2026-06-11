#include<bits/stdc++.h>
using namespace std;
int main(void){
string s,t;cin>>s>>t;
int n=s.length(),c,p=0;
char x[n+1],y[n+1];
strcpy(x,s.c_str());
strcpy(y,t.c_str());
while(p<n-1){
for(int i=0;i<n;i++){
    if(x[i]!=y[i])
        break;
    if(i==(n-1)){
        cout<<"Yes"<<endl;return 0;
    }}
for(int i=0;i<n;i++){
    if(i==(n-1))
        break;
    c=x[n-1];
    x[n-1]=x[i];
    x[i]=c;
}
p+=1;
}
for(int i=0;i<n;i++){
    if(x[i]!=y[i])
        break;
    if(i==(n-1)){
        cout<<"Yes"<<endl;return 0;
    }}
cout<<"No"<<endl;
return 0;}
