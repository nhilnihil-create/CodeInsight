#include <algorithm>
#include <bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;
#define rep(i, n) for (int i = 0; i <(int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
const ll MOD=1000000007;
const ll M=100005;
bool isPrime(long long x){
  if(x == 1)return 0;
  for(long long i = 2; i*i <= x; i++) if(x%i == 0) return 0;
  return 1;
}
int main(){
 ll q;cin>>q;
 vector<int> b(M);
 for(int i=1;i<=M;i+=2){
   if(isPrime(i)&&isPrime((i+1)/2))b[i]=1;
 }
 vector<ll>sum(M);
 for(int i=1;i<=M;i++)b[i+1]+=b[i];
 int l[q],r[q];
 rep(i,q){
   cin>>l[i]>>r[i];
 }
 rep(i,q){
   ll ans=0;
   ans=b[r[i]]-b[l[i]-1];
   cout << ans << endl;
 }

}