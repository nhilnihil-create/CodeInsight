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
for(ll i=0; i<5; i++){
cin>>a[i];}
sort(a,a+5);
ll mi=a[0];
ll t=4+n/mi;
if(n%mi!=0) t++;
cout<<t<<endl;}
