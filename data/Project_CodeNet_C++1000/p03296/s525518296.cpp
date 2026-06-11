#include <bits/stdc++.h>
using namespace std;
int main() {
long long N;
cin>>N;
long long counter=0;
long long a[N+10]={};
for(long long i=0;i<N;i++){
cin>>a[i];}
for(long long i=0;i<N;i++){
if(a[i]==a[i+1]){
if(a[i+1]==a[i+2]){
counter++;
i++;
continue;}
else{
counter++;
i++;
continue;}}
else{
continue;}}
cout<<counter<<endl;}
