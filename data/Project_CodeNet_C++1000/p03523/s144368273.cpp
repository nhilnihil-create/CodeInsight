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
string s;
cin>>s;
ll k=0;
string t = "";
ll n=s.size();
if(n>9){
cout << "NO" << endl;}
else{

for(ll i=0; i<n; i++){
if(s.at(i)!='A'){
t+=s.at(i);}}
string u="KIHBR";
if(t!=u){
cout << "NO" << endl;}

else{
  
ll ca=0;
while(s.at(ca)=='A'){
ca++;}
if(ca>1){
cout << "NO" << endl;}
else if(s.at(ca+1)!='I'||s.at(ca+2)!='H'){
cout << "NO" << endl;}
  
else{
  
ca++;
ca++;
ca++;
while(s.at(ca)=='A'){
ca++;
k++;}
if(k>1){
cout << "NO" << endl;}
  
else{
  
k=0;
ca++;
while(s.at(ca)=='A'){
ca++;
k++;}
if(k>1){
cout << "NO" << endl;}
else if(n-ca<=2){
cout << "YES" << endl;}
else{
cout << "NO" << endl;}
}}}}}
