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
ll n;
cin>>n;
ll a[n]={},b[n]={};
ll ca=0,cb=0,cc=0;
for(ll i=0; i<n; i++){
cin>>a[i];}
for(ll i=0; i<n; i++){
cin>>b[i];}
for(ll i=0; i<n; i++){
if(a[i]>b[i]){
ca+=a[i]-b[i];}
else{
cc+=(b[i]-a[i]+1)/2;
cb+=b[i]-a[i];}}
if(-ca+cb>=cc){
cout <<"Yes" << endl;}
else{
cout << "No" << endl;}}
