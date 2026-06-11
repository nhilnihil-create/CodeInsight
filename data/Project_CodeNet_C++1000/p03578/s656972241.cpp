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
map<ll,ll> a;
ll r;
for(ll i=0; i<n; i++){
cin>>r;
a[r]++;}
ll m;
cin>>m;
map<ll,ll> b;
for(ll i=0; i<m; i++){
cin>>r;
b[r]++;}
ll k=0;
for(auto p:b){
if(b[p.first]>a[p.first]){
k++;
break;}}
if(k==1){
cout << "NO" << endl;}
else{
cout << "YES" << endl;}}
