#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
const ll mod=1000000007;
/* 4 方向への隣接頂点への移動を表すベクトル */
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };
int main() {
ll n,m;
cin>>n>>m;
ll ca=0;
ll f=0;
for(ll i=1; i*n<=m; i++){
if(m%i==0){
ca=i;
if(ca>=n){
f++;
break;}}}
if(f==1){
cout<<m/ca<<endl;}
else{
cout<<ca<<endl;}}
