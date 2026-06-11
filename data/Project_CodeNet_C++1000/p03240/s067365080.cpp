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
ll x[n]={},y[n]={},h[n]={};
ll ha=0;
ll b=0;
ll e=-1;
for(ll i=0; i<n; i++){
cin>>x[i]>>y[i]>>h[i];}
for(ll i=0; i<n; i++){
if(h[i]!=0){
e=i;
break;}}
for(ll i=0; i<=100; i++){
for(ll k=0; k<=100; k++){
ha=abs(i-x[e])+abs(k-y[e])+h[e];
for(ll q=0; q<n; q++){
if(q==e) continue;
if(!(ha-abs(i-x[q])-abs(k-y[q])==h[q]||(ha-abs(i-x[q])-abs(k-y[q])<=0&&h[q]==0))){
b++;	
break;}}
if(b==0){
cout<<i<<" "<<k<<" "<<ha;
goto end;}
b=0;}}
end:
cout<<endl;}
