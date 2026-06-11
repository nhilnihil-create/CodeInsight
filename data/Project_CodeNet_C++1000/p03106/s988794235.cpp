#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int n,m,k;
  cin >> n>>m>>k;
  int g=__gcd(n,m);
  vector<int>a;
  for(int i=g;i>=1;i--){
    if(g%i==0){
      a.push_back(i);
    }
  }
  
  cout<<a.at(k-1)<<endl;
 
}

