#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const ll INF = 1e18;

int main(){
  int n;
  cin >> n;
  vector<string> w(n);
  rep(i,n) cin >> w[i];

  for(int i = 1; i<n; i++){
    if(*w[i].begin()!=*w[i-1].rbegin()){
      cout << "No" << endl;
      return 0;
    }
  }

  sort(w.begin(),w.end());

  for(int i = 1; i<n; i++){
    if(w[i]==w[i-1]){
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;

  return 0;
}