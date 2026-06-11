#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int i, N, K, count=0, A=0, B=0;
  vector<ll> a(110);
  ll x;
  
  cin >> N >> x;
  rep(i,N) cin >> a[i];
  

  sort(a.begin(),a.begin()+N);
  
  
  for(i=0;i<N;i++){
    x-=a[i];
    if(x>=0) count+=1;
    else break;
  }
  
  if(x>0)count-=1;
  
  cout << count;
  
}
  
  


