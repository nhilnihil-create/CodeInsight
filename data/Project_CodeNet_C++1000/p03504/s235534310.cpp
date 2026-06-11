#include <bits/stdc++.h>
#define P pair<int , int>

using namespace std;

int main(){
  int n, C;
  vector<P> v[31];
  cin >> n >> C;
  for(int i=0;i<n;i++){
    int s, t, c;
    cin >> s >> t >> c;
    c--;
    v[c].push_back(P(s, t));
  };
  priority_queue<P, vector<P>, greater<P> > q1;
  priority_queue<int , vector<int>, greater<int> > q2;
  for(int i=0;i<C;i++){
    sort(v[i].begin(), v[i].end());
    int s=-1, t=-1;
    for(int j=0;j<v[i].size();j++){
      if(s==-1){
        s = v[i][j].first;
        t = v[i][j].second;
      }
      else if(v[i][j].first==t){
        t = v[i][j].second;
      }
      else if(v[i][j].first!=t){
        q1.push(P(s, t));
        s = v[i][j].first;
        t = v[i][j].second;
      }
      if(j==v[i].size()-1){
        q1.push(P(s, t));
      }
    }
  }
  int ans=0;
  while(!q1.empty()){
    while(!q2.empty() && q1.top().first>q2.top())q2.pop();
    q2.push(q1.top().second);q1.pop();
    ans = max(ans, (int)q2.size());
  }
  cout << ans << endl;
}

