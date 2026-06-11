#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(obj) (obj).begin(), (obj).end()
#define bit(n) (1LL << (n))

using namespace std;

typedef long long ll;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false); 
  
  int n = 5;
  int d[5];
  cin>>d[0]>>d[1]>>d[2]>>d[3]>>d[4];
 
  int max = -1;
  int index = 0;
  
  rep(i,n) {
    int target = d[i];
    int diff = 0;
    
    while(target % 10 != 0) {
      ++diff;
      ++target;
    }
    if(diff>=max) {
      max = diff;
      index = i;
    }
  }  
  
  int sum = 0;
  rep(i,n) {
    if(index == i) continue;
    
    int target = d[i];
    sum += target;
    while(sum % 10 != 0) {
      ++sum;
    }
  }
  
  sum += d[index];
  cout<<sum;
    
  return 0;
}