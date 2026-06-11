#include <bits/stdc++.h>
using namespace std;
int main(){
int counter=0;
string a;
cin>>a;
for(int i=0;i<3;i++){
if(a.at(i)=='a'){
counter++;
break;}}
for(int i=0;i<3;i++){
if(a.at(i)=='b'){
counter++;
break;}}
for(int i=0;i<3;i++){
if(a.at(i)=='c'){
counter++;
break;}}
if(counter==3)
cout<<"Yes"<<endl;
else
cout<<"No"<<endl;}
