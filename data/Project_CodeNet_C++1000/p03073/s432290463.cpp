#include<stdio.h>
#include<iostream>
#include<vector>
#include<math.h>
#include<queue>
#include<map>
#include<algorithm>
#include<string.h>
#include<functional>
#include<limits.h>
#include<stdlib.h>
#include<cmath>
#include<cstring>
#include<set>
#include<climits>
#include<bitset>
using namespace std;

#define intmax INT_MAX
#define lmax LONG_MAX
#define uintmax UINT_MAX
#define ulmax ULONG_MAX
#define llmax LLONG_MAX
#define ll long long
#define rep(i,a,N) for((i)=(a);(i)<(N);(i)++)
#define rrp(i,N,a) for((i)=(N)-1;(i)>=(a);(i)--)
#define llfor ll i,j
#define sc(a) cin>>a
#define pr(a) cout<<a<<endl
#define pY puts("YES")
#define pN puts("NO")
#define py puts("Yes")
#define pn puts("No")
#define pnn printf("\n")
#define pb push_back
#define all(a) a.begin(),a.end()
#define llvec vector<vector<ll>>
#define charvec vector<vector<char>>
#define llpvec vector<pair<ll,ll>>
#define size_(a,b) (a,vector<ll>(b))
#define S 3
int main(){
 string s;
 cin>>s;
 ll n=s.length();
  
 //010101......
 ll cnt1=0;
 for(int i=0;i<n;++i){
  if(i%2!=(s[i]-'0'))cnt1++;
 }
 cout<<min(cnt1,n-cnt1)<<endl;
 return 0;}