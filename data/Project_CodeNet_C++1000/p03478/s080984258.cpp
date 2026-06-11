#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main () {
  int i, j, k, N, A, B, z, count=0, ans=0, sum;
  
  cin >> N >> A >> B;
  
  rep(i,N){
    z=i+1;
    sum=0;
    for(;z!=0;){
      sum+=z%10;
      z/=10;
    }
    if(sum>=A && sum<=B) ans +=i+1;
  }
  
  cout << ans;
}


