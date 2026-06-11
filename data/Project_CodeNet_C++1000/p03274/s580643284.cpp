#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,K;
  cin >> N >> K;
  vector<int64_t> v(N);
  for(int i=0;i<N;i++){
    cin >> v.at(i);
  }
  int64_t mi=1e18;
  for(int i=0;i<N-K+1;i++){
    int64_t l=v.at(i);
    int64_t r=v.at(i+K-1);
    int64_t res=abs(l-r)+min(abs(l),abs(r));
    if(mi>res){
      mi=res;
    }
  }
  cout << mi << endl;
  return 0;
}
