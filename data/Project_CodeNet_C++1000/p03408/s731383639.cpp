#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main(){
  int N, M;
  cin >> N;
  map<string,int> m;
  vector<string> s(N);
  for(int i=0; i<N; i++){
    cin >> s.at(i);
    m[s.at(i)]++;
  }
  cin >> M;
  vector<string> t(M);
  for(int i=0; i<M; i++){
    cin >> t.at(i);
    m[t.at(i)]--;
  }
  int ans = 0;
  for(string S: s){
    ans=max(ans,m[S]);
  }
  cout << ans;
  return 0;
}