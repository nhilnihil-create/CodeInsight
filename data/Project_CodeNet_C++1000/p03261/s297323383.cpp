#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<string> a(n);
  rep(i,n) cin >> a.at(i);

  for(int i = 1; i <n; i++){
    if(a.at(i).front() != a.at(i-1).back()){
      cout << "No" << endl;
      return 0;
    }
  }
  set<string> b;
  rep(i,n) b.insert(a.at(i));
  if(a.size() != b.size()){
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;

 }
