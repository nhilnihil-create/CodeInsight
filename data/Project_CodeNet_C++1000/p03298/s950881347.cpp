#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){
  int N;
  string S;
  cin >> N >> S;
  vector<map<string,int>> mp(N+1);
  for(int i = 0; i < (1<<N); ++i){
    string A(N,'?');
    int a = 0, b = 0;
    for(int j = 0; j < N; ++j){
      if((i>>j)&1) A[a++] = S[j];
      else A[N-1-b++] = S[j];
    }
    ++mp[a][A];
  }
  long long ans = 0;
  for(int i = 0; i < (1<<N); ++i){
    string A(N,'?');
    int a = 0, b = 0;
    for(int j = 0; j < N; ++j){
      if((i>>j)&1) A[a++] = S[2*N-1-j];
      else A[N-1-b++] = S[2*N-1-j];
    }
    ans += mp[a][A];
  }
  cout << ans << endl;
}
