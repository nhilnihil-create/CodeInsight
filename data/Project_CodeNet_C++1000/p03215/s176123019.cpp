#include <bits/stdc++.h>
using namespace std;

int N,K;
bitset<43> ans(0);
vector<long long> sum;

bool calc(){
  int cnt=0;
  for(int i=0;i<N+1;i++){
    for(int j=i;j<N+1;j++){
      long long tmp=sum.at(j)-sum.at(i);
      if((ans.to_ullong()&tmp)==ans.to_ullong())  cnt++;
    }
  }
  if(cnt>=K)  return true;
  else  return false;
}

int main(){
  cin >> N >> K;
  vector<long long> a(N);
  for(int i=0;i<N;i++)  cin >> a.at(i);

  sum.resize(N+1);
  for(int i=0;i<N;i++)  sum.at(i+1)=sum.at(i)+a.at(i);
  for(int i=42;i>=0;i--){
    bool flag=true;
    ans.set(i,1);
    flag=calc();
    if(!flag) ans.set(i,0);
  }
  cout << ans.to_ullong() << endl;

  return 0;
}