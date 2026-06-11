#include <bits/stdc++.h>
using namespace std;
int main() {
long long N;
cin>>N;
long long a,b;
long long counter=0;
long long c=100000000000;
for(long long i=1;i<N;i++){
a=i;
b=N-a;
while(a>0){
counter+=a%10;
a/=10;}
while(b>0){
counter+=b%10;
b/=10;}
c=min(counter,c);
counter=0;}
cout<<c<<endl;}
