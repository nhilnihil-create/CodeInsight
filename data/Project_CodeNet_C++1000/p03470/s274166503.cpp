#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int i, N, count=0;
  vector<int> d(110);
  
  cin >> N;
  rep(i,N) cin >> d[i];
  
  sort(d.begin(),d.begin()+N);
  
  rep(i,N-1){
    if(d[i]!=d[i+1])count+=1;
  }
  
  cout << count+1;
  
}