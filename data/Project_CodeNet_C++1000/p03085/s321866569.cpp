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
cout << fixed << setprecision(10);
string s;
cin>>s;
if(s.at(0)=='A'){
cout<<'T'<<endl;}
else if(s.at(0)=='T'){
cout<<'A'<<endl;}
else if(s.at(0)=='C'){
cout<<'G'<<endl;}
else if(s.at(0)=='G'){
cout<<'C'<<endl;}}
