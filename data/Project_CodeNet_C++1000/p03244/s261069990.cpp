#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
const ll mod=1000000007;
/* 4 方向への隣接頂点への移動を表すベクトル */
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };
int main() {
ll n;
cin>>n;
ll ca=0;
ll f=0;
ll a[n]={};
ll b[100005]={};
ll c[100005]={};
ll d[100005]={};
ll e[100005]={};
for(ll i=0; i<n; i++){
cin>>a[i];}
for(ll i=0; i<n; i=i+2){
b[a[i]]++;
d[a[i]]++;}
for(ll i=1; i<n; i=i+2){
c[a[i]]++;
e[a[i]]++;}
sort(d,d+100005);
sort(e,e+100005);
ll bm=d[100004];
ll cm=e[100004];
ll bi,ci;
ll bmm,cmm;
for(ll i=0; i<100005; i++){
if(b[i]==bm){
bi=i;}}
for(ll i=0; i<100005; i++){
if(c[i]==cm){
ci=i;}}
if(bi!=ci){
cout<<n-bm-cm<<endl;
}
else{
bmm=d[100003];
cmm=e[100003];
cout<<n-max(bm+cmm,bmm+cm)<<endl;}}
