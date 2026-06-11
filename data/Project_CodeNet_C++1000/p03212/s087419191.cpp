#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};

 
int main(){
  ll n;
  cin >> n;
  priority_queue<ll, vector<ll>, greater<ll>> que;
  que.push(3LL);
  que.push(5LL);
  que.push(7LL);
  vector<ll> ans;
  while(true){
    ll tmp =  que.top();
    que.pop();
    if(tmp>n) break;
    ans.push_back(tmp);
    que.push(tmp*10+3LL);
    que.push(tmp*10+5LL);
    que.push(tmp*10+7LL);
  }
  int cnt = 0;
  for(int i=0; i<ans.size(); i++){
    string k = to_string(ans[i]);
    set<int> st;
    for(int j=0; j<k.length(); j++){
      st.insert(k[j]);
    }
    if(st.size()==3) cnt++;
  }
  cout << cnt << endl;
  return 0;
}
