#include <iostream>
#include <vector>
using namespace std;

int main(){
  int N;
  cin >> N;
  string S;
  cin >> S;
  vector<int> e(N+1), w(N+1);
  int num_e = 0;
  for(int i=0; i<N; i++){
    if(S.at(i)=='E'){
      num_e++;
    }
    e.at(i+1) = num_e;
    w.at(i+1) = i+1-num_e;
  }
  int ans = N;
  for(int i=0; i<N; i++){
    int nw = w.at(i);
    int ew = e.at(N)-e.at(i+1);
    ans = min(ans,nw+ew);
  }
  cout << ans;
  return 0;
}