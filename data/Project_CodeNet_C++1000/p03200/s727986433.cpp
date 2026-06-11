#include <bits/stdc++.h>
using namespace std;
int main(){
long long counter;
counter=0;
long long counter2=0;
string S; cin>>S;
for(long long i=0; i<S.size();i++){
if(S.at(i)=='B'){
counter2++;}
else
counter+=counter2;}
cout<<counter<<endl;}