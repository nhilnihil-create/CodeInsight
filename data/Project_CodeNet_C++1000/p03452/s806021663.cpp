#include <iostream>
#include <vector>
#include <map>
#include <stack>
using namespace std;

typedef pair<int, int> pii;
vector<pii> v[100001];
int h[100001];
bool used[100001];
int x[100001];

bool dfs(int p)
{
  used[p] = true;
  for(auto u : v[p]){
    if(used[u.first]){
      if(x[p] + u.second != x[u.first]) return false;
    } else {
      x[u.first] = x[p] + u.second;
      if(!dfs(u.first)) return false;
    }
  }
  return true;
}

int main()
{
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < m; i++){
    int l, r, d;
    cin >> l >> r >> d;
    v[l].push_back(make_pair(r, d));
    h[r]++;
  }

  stack<int> st;
  for(int i = 1; i <= n; i++)
    if(h[i] == 0)
      st.push(i);

  vector<int> ans;
  while(st.size()){
    int i = st.top();
    st.pop();
    ans.push_back(i);
    for(auto u : v[i]){
      h[u.first]--;
      if(h[u.first] == 0) st.push(u.first);
    }
  }

  if(ans.size() != n){
    cout << "No" << endl;
    return 0;
  }

  for(int i = 0; i < n; i++){
    if(!used[ans[i]]){
      if(!dfs(ans[i])){
        cout << "No" << endl;
        return 0;
      }
    }
  }

  cout << "Yes" << endl;

  return 0;
}