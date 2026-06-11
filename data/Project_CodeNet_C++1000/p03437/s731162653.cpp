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
ll x,y;
cin>>x>>y;
if(x%y==0){
cout << -1 << endl;}
else{
for(ll i=1; i<1000000000; i++){
if(x*i%y!=0){
cout << x*i << endl;
break;}}
}}
