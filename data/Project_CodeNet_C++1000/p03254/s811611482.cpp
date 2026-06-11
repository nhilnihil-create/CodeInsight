#include <bits/stdc++.h>
using namespace std;
int main() {
long long N;
cin>>N;
long long counter=0;
long long a[N]={};
long long x;
cin>>x;
for(long long i=0;i<N;i++){
cin>>a[i];}
sort(a,a+N);
for(long long i=0;i<N;i++){
if(x-a[i]>0){
counter++;
x-=a[i];
continue;}
else if (x-a[i]==0){
x-=a[i];
counter++;
break;
}
else
break;}
if(N==counter&&x>0){
  counter--;}
cout<<counter<<endl;}
