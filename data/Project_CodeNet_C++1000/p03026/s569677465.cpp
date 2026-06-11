#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const int INF = 1001001001;

int main(){
  int n; cin >> n;
  vector<int> assign(n,-1);
  vector<vector<int>> to(n,vector<int>(0));
  for(int i=0;i<n-1;i++){
    int a,b;
    cin >> a >> b;
    a--; b--;
    to.at(a).push_back(b);
    to.at(b).push_back(a);
  }
  vector<int> c(n,0);
  for(int i=0;i<n;i++) cin >> c.at(i);
  sort(c.rbegin(),c.rend());
  assign.at(0) = c.at(0);
  queue<int> q;
  q.push(0);
  ll j = 1;
  while(q.size()){
    int x = q.front();
    q.pop();
    for(auto y:to.at(x)){
      if(assign.at(y)!=-1) continue;
      assign.at(y) = c.at(j); j++;
      q.push(y);
    }
  }
  ll m = 0;
  for(int i=1;i<n;i++){
    m += c.at(i);
  }
  cout << m << endl;
  for(int i=0;i<n;i++){
    cout << assign.at(i) << " ";
  }
}