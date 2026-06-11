#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<ll>D(n);
  for(int i = 0;i < n;i++) cin >> D[i];
  sort(D.begin(),D.end());
  queue<ll> que;
  for(int i = 0;i < n;i++) que.push(D[i]);
  int m;
  cin >> m;
  vector<ll>T(m);
  for(int i = 0;i < n;i++) cin >> T[i];
  sort(T.begin(),T.end());
  int c = 0;
  while(!que.empty()){
    if(T[c] == que.front()) c++;
    que.pop();
    if(c == m){
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
}
