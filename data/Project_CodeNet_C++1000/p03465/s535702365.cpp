/*
 
dunjen_master
 
*/
 
 
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
 
#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
 
using namespace std;
 
const int MAX_N = int(1e6) + 10;
const long long int MOD=1e9+7;
const long long int INF=1e18;
 
typedef long long int ll;
typedef unsigned long long int llu;
 
 
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// #define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>

inline ll mul(ll a,ll b){

    a=(a+MOD)%MOD;
    b=(b+MOD)%MOD;
    ll c=a*b;
    c=(c+MOD)%MOD;
    return c;
}
inline ll add(ll a,ll b){
    a=(a+MOD)%MOD;
    b=(b+MOD)%MOD;
    ll ans=(a+b);
    ans=(ans+MOD)%MOD;
    return ans;
}
ll power(ll a,ll b,ll c=0){
    ll ans=1;
    while(b){
        if(b&1){
            ans=mul(ans,a);
        }
        a=mul(a,a);
        b=b/2;
    }
    return ans;
}
template<class T1, class T2>
istream &operator>>(istream &in, pair<T1, T2> &P){
    in >> P.first >> P.second;
    return in;
}
 
template<class T1, class T2>
ostream &operator<<(ostream &out, const pair<T1, T2> &P){
    out << "(" << P.first << ", " << P.second << ")";
    return out;
}
template<class T>
istream &operator>>(istream &in, vector<T> &arr){
    for(auto &x: arr) in >> x;
    return in;
}
template<class T>
ostream &operator<<(ostream &out, const vector<T> &arr){
    for(auto &x: arr) out << x << ' '; cout << "\n";
    return out;
}
template<class T>
istream &operator>>(istream &in, deque<T> &arr){
    for(auto &x: arr) in >> x;
    return in;
}
template<class T>
ostream &operator<<(ostream &out, const deque<T> &arr){
    for(auto &x: arr) out << x << ' '; cout << "\n";
    return out;
}
mt19937 rnd(time(0));
 
inline ll gcd(ll a,ll b){
    while(b)a%=b,swap(a,b);
    return a;
}
  

 
#define all(x) (x).begin(),(x).end()

/* ordered_set A;
   A.insert(x);
   A.erase(x);
   A.order_of_key(x) // no of elements less than (<) x
   *A.find_by_order(k-1) // kth smallest element
*/


const int N=1e5+5;


int n;
bitset<4000005>bit[2];
int a[2005];
int sum=0;



int main(){
 

  
  

    cin>>n;
  
    for(int i=1;i<=n;i++){
    cin>>a[i];
    }
    int r=0; 
    bit[0][0]=1;
  
  
  
  for(int i=1;i<=n;i++){
    
    bit[r^1]=bit[r];
    bit[r^1]|=(bit[r]<<a[i]);r=r^1;
  
    sum+=a[i];
  }
  
  for(int i=(sum+1)/2;i<=sum;i++){
    if(bit[r][i]){
      cout<<i<<endl;
      return 0;
    }
  }
  
  return 0;
}

   

    


    


    
    
    
    
 
    
