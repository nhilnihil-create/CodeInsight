#include <bits/stdc++.h>

using ll = long long;
using namespace std;
const int INFint = 2e9+1;
const ll INFll = 2e18+1;
ll MOD=1e9+7;

int main(){
  int N,M;
  cin>>N;
  vector<int> D(N);
  for(int i(0);i<N;i++) cin>>D[i];
  cin>>M;
  vector<int> T(M);
  for(int i(0);i<M;i++) cin>>T[i];
  if(M > N){
    cout << "NO" << endl;
    return 0;
  }
  map<int,int> m;
  for(int i(0);i<N;i++){
    m[D[i]]++;
  }
  for(int i(0);i<M;i++){
    if (m[T[i]] > 0){
      m[T[i]]--;
    }else{
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  return 0;
}
