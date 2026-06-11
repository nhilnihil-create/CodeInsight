#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
const ll mod=1000000007;
const int MAX_N = 1000;         // n の最大値

// nCk を取得
void f(int res , string s){
     if(res==0){
       cout << s << endl;}
   else{
     for(char c='a'; c<='c'; c++){
        f(res -1, s + c);}
   }
}
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
int N;
cin>>N;
int a[N]={};
int ca=0;
int d=0;
int u=0;
int ma=0;
int mi=0;
for(int i=0; i<N; i++){
cin>>a[i];}
for(int i=0; i<N-1; i++){
ma=max(ma,a[i]);
mi=min(mi,a[i]);
if(d==0&&a[i]>a[i+1]){
ca+=a[i]-mi;
d++;
ma=0;
mi=a[i+1];}
else if(a[i]<a[i+1]){
d=0;}}
ma=max(ma,a[N-1]);
if(d==0){
ca+=a[N-1]-mi;}
cout<<ca<<endl;}
