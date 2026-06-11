#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

ll gcd(ll x,ll y){
    if (y==0) return x;
    return gcd(y,x%y);
}

int main(){
  int n;
  cin>>n;
  int a[n];
  rep(i,0,n) cin>>a[i];
  int cur=a[0];
  rep(i,1,n){
    cur=gcd(cur,a[i]);
  }
  cout<<cur<<endl;
}