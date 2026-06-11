#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int i, N, a[110], count=0, A=0, B=0;
  
  cin >> N;
  rep(i,N) cin >> a[i];
  
  sort(a,a+N,greater<int>());
  
  for(i=0;i<N/2;i++){
    A+=a[2*i];
    B+=a[2*i+1];
  }
  
  if(N%2==1) A+=a[N-1];
  
  cout << A-B;
  
}