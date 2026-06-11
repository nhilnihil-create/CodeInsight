#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
 
int main() {
ll n;
cin>>n;
ll ca=10000000000;
ll counter=0;
ll a[n]={};
ll cb=10000000000;
ll cc;
ll f=0;
ll counter1;
ll cd;
ll ce;
for(ll i=0;i<n;i++){
cin>>a[i];}
sort(a,a+n);
cout<<a[n-1]<<" ";
if(a[n-1]%2==0){
counter=a[n-1]/2;
for(ll i=0; i<n; i++){
if(counter<a[i]){
ca=i;
break;
}}

if(abs(counter-a[ca-1])>abs(counter-a[ca])){
cout<<a[ca]<<endl;}
else
cout<<a[ca-1]<<endl;}

else{
counter=a[n-1]/2;
for(ll i=0; i<n; i++){
if(counter<a[i]){
ca=i;
break;
}}

counter1=a[n-1]/2+1;
for(ll i=0; i<n; i++){
if(counter1<a[i]){
cb=i;
break;
}}

if(abs(counter-a[ca-1])>abs(counter-a[ca])){
cc=abs(counter-a[ca]);}
else{
cc=abs(counter-a[ca-1]);}

if(abs(counter1-a[cb-1])>abs(counter1-a[cb])){
cd=abs(counter1-a[cb]);}
else{
cd=abs(counter1-a[cb-1]);}

if(cc>cd){
if(abs(counter1-a[cb-1])>abs(counter1-a[cb])){
cout<<a[cb]<<endl;}
else
cout<<a[cb-1]<<endl;}
 
else{
if(abs(counter-a[ca-1])>abs(counter-a[ca])){
cout<<a[ca]<<endl;}
else
cout<<a[ca-1]<<endl;}}}
