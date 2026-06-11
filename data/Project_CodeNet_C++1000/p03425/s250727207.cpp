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
ll a[5]={};
ll counter=0;
ll i=0;
string s;
for(ll k=0; k<n; k++){
cin>>s;
if(s.at(0)=='M'){
a[0]++;}
else if(s.at(0)=='A'){
a[1]++;}
else if(s.at(0)=='R'){
a[2]++;}
else if(s.at(0)=='C'){
a[3]++;}
else if(s.at(0)=='H'){
a[4]++;}}
for(ll i=0; i<5; i++){
for(ll n=i+1; n<5; n++){
for(ll m=n+1; m<5; m++){
counter+=a[i]*a[n]*a[m];}}}
cout<<counter<<endl;}
