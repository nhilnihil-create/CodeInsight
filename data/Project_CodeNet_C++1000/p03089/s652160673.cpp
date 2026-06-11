#include <bits/stdc++.h>

using ll = long long;
using namespace std;
const int INFint = 2e9+1;
const ll INFll = 2e18+1;
ll MOD=1e9+7;


int main() {
  int N;
  cin>>N;
  vector<int> b(N);
  for(int i(0);i<N;i++){
    cin>>b[i];
  }
  vector<int> ans;
  for(int i(0);i<N;i++){
    int maxi(-1);
    for(int j(0);j<int(b.size());j++){
      if(b[j] == j+1){
        maxi = j;
      }
    }
    //cout << maxi << endl;
    if(maxi == -1){
      cout << -1 << endl;
      return 0;
    }
    ans.push_back(b[maxi]);
    b.erase(b.begin()+maxi);
  }
  for(int i(0);i<N;i++){
    cout << ans[N-i-1] << endl;
  }
}