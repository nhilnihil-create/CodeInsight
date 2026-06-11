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
for(ll i=1; i<=3500; i++){
for(ll k=1; k<=3500; k++){
if((4*i*k-n*k-n*i)>0&&(n*k*i)%(4*i*k-n*k-n*i)==0){
if(n*k*i<=3500*(4*i*k-n*k-n*i)){
cout << i << " " << k << " " << (n*k*i)/(4*i*k-n*k-n*i);
goto asd;
}
}}}
asd: 
cout << endl;
return 0;}

