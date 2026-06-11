#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define rep2(i,a,n) for(int i=(a); i<(n); i++)
#define all(vec) vec.begin(),vec.end()
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;

int main(){
  int N; cin >> N;
  map<string, int> mp;
  vector<string> W(N);
  rep(i,N){
    cin >> W[i];
    mp[W[i]]++;
  }
  
  rep2(i,1,N){
    if(W[i][0] != W[i-1][W[i-1].size()-1]) {cout << "No" << endl; return 0;}
  }
  
  for (auto itr : mp){
    if(itr.second > 1)  {cout << "No" << endl; return 0;}
  }
  
  cout << "Yes" << endl;
  return 0;
}