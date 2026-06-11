#include <cstring>
#include <iostream>
#include <numeric>
#include <bits/stdc++.h>
using namespace std;
int main(){
int N,t=0;
cin>>N;
int a[N],b[N],c[N],d;
for(int i=0;i<N-1;i++){
cin>>a[i]>>b[i]>>c[i];}
for(int j=0;j<N-1;j++){
for(int i=j;i<N-1;i++){
if(t<=b[i]){d+=b[i]+a[i];}
else if(t%c[i]==0){d+=t+a[i];}
else {d+=t+a[i]+(c[i]-t%c[i]);}
t=d;
d=0;}
cout<<t<<endl;
t=0;}
cout<<0<<endl;
}

