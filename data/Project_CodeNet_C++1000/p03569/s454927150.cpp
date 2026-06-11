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
string s;
cin>>s;
string t = "";
ll n=s.size();
for(ll i=0; i<n; i++){
if(s.at(i)!='x'){
t+=s.at(i);}}
string u=t;
reverse(t.begin(), t.end());
if(t!=u){
cout << -1 << endl;}
else if(t.size()==0){
cout << 0 << endl;}
else{
ll ca=0;
ll m=0,h=n-1;
ll cm=0;
ll ch=0;
while(h!=m){
while(s.at(m)=='x'){
cm++;
m++;}
while(s.at(h)=='x'){
ch++;
h--;}
ca+=abs(cm-ch);
cm=0;
ch=0;
m++;
h--;
if(h-m<=0){
break;}}
cout << ca << endl;}}
