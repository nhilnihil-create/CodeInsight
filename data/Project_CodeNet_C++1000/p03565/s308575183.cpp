#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
const ll mod=1000000007;
const int MAX_N = 1000;         // n の最大値
 
// nCk を取得
double nCk(int n, int k) {
double res=1.0;
for(int i=0; i<n; i++){
res*=0.5;}
for(int i=0; i<k; i++){
res*=(double)(n-i);
res/=(double)(k-i);
}
return res;}
 
int main() {
string s,t;
cin>>s>>t;
ll q=s.size();
ll w=t.size();
string a;
ll ca=0;
ll p=-1;
for(ll i=0; i<q-w+1; i++){
a=s.substr(i,w);
while(ca<w){
if(a.at(ca)==t.at(ca)||a.at(ca)=='?') {
ca++;
continue;}
else{
break;}}
if(ca==w){
p=i;}
ca=0;}
if(p==-1){
cout<<"UNRESTORABLE"<<endl;}
else{
for(ll i=0; i<p; i++){
if(s.at(i)=='?'){
cout<<"a";}
else
cout<<s.at(i);}
cout<<t;
for(ll i=p+w; i<q; i++){
if(s.at(i)=='?'){
cout<<"a";}
else
cout<<s.at(i);}}}
