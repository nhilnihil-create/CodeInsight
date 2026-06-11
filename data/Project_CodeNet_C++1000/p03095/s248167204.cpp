#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t N;
  string S;
  cin>>N>>S;
  int64_t Q=1000000007,Z=1;
  vector<int> p(26);
  for(int i=0;i<N;i++){
    p.at(S.at(i)-'a')++;
  }
  for(int i=0;i<26;i++){
    Z*=(p.at(i)+1);
    Z=Z%Q;
  }
  Z+=Q-1;
  Z=Z%Q;
  cout<<Z<<endl;
}