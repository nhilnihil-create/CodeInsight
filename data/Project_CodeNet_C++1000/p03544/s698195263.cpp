#include <bits/stdc++.h>
using namespace std;

vector<int64_t> d;

int64_t Luca(int N){
  if(d.at(N)>=0) return d.at(N);
  if(N==0){
    return d.at(N)=2;
  }
  if(N==1){
    return d.at(N)=1;
  }
  int64_t s = Luca(N-1);
  int64_t t = Luca(N-2);
    return d.at(N)=s+t;
}

int main(){
  int N;
  cin >> N;
  for(int i=0;i<=N;i++) d.push_back(-1);

  cout<< Luca(N) << endl;
}
