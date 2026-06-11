#include <bits/stdc++.h>
using namespace std;
int main() {
  string S;int K;
  cin>>S>>K;int N=S.size();
  vector<string> p;
  for(int i=1;i<=K;i++){
    for(int j=0;j<=N-i;j++){
      string a=S.substr(j,i);
      p.push_back(a);
    }
  }
  sort(p.begin(), p.end());
  int a=0;K--;
  while(K>0){
    if(p.at(a)!=p.at(a+1)) K--;
    a++;
  }
  cout<<p.at(a)<<endl;
}