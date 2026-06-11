#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <set>
using namespace std;

long long int ans = -1000000000, n;

void func2(vector<int>& v, vector<vector<int> >& f, vector<vector<int> >& p){
  long long int ret = 0;
  for(int i = 0; i < n; i++){
    int x = 0;
    for(int j = 0; j < 10; j++){
      if(v[j] == 1 && f[i][j] == 1) x++;
    }
    ret += p[i][x];
  }
  ans = max(ret, ans);
  return;
}

void func(vector<int>& v, vector<vector<int> >& f, vector<vector<int> >& p){
  if(v.size() == 10){
    int i;
    for(i = 0; i < v.size(); i++){
      if(v[i] != 0) break;
    }
    if(i == v.size()) return;
    //for(int i = 0; i < v.size(); i++) cout << v[i]; cout << endl;
    func2(v, f, p);
    return;
  }
  v.push_back(0);
  func(v, f, p);
  v.pop_back();
  v.push_back(1);
  func(v, f, p);
  v.pop_back();
  return;
}

void solve(){
  cin >> n;
  vector<vector<int> > f(n, vector<int>(10));
  for(int i = 0; i < n; i++){
    for(int j = 0; j < 10; j++){
      cin >> f[i][j];
    }
  }
  vector<vector<int> > p(n, vector<int>(11));
  for(int i = 0; i < n; i++){
    for(int j = 0; j < 11; j++){
      cin >> p[i][j];
    }
  }
  vector<int> v;
  func(v, f, p);
  cout << ans << endl;
  return;
}

int main(){
  solve();
  return 0;
}
