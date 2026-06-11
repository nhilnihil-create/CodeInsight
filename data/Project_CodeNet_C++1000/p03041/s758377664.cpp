#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(v) sort(v.begin(), v.end())
typedef long long ll;
using Graph = vector<vector<int>>;

int main(){
  int n, k;
  cin >> n >> k;
  vector<char> s(n);
  rep(i,n){
    cin >> s.at(i);
  }
  rep(i,n){
    if(i==k-1){
      s.at(i) = tolower(s.at(i));
    }
  }
  rep(i,n){
    cout << s.at(i);
  }
  cout << endl;
}
