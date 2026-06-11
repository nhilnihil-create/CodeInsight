#include <bits/stdc++.h>
using namespace std;
int main() {
string s;
cin>>s;
int counter=0;
for(int i=0;i<s.size()-1;i++){
if(s.at(i)==s.at(i+1)){
counter++;
if(s.at(i+1)=='0'){
s.at(i+1)='1';}
else 
s.at(i+1)='0';}
else
continue;}
cout<<counter<<endl;}