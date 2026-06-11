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
ll q;
ll a1=0;
ll o=0;
ll p=0;
for(ll i=0; i<n; i++){
cin>>q;
if(q%2==0){
p++;}
else if(q==1){
a1++;}
else{
o++;}}
ll ca=0;
ca=pow(3,n)-pow(2,p);
cout << ca << endl;}
