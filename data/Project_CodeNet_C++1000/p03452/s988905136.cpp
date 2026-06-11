#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi=vector<int>;
using vvi=vector<vi>;
using vl=vector<ll>;
using vvl=vector<vl>;
using pii = pair<int,int>;
using pli = pair<ll,int>;
using pll = pair<ll,ll>;
using vpii = vector<pii>;
using vpli = vector<pli>;
using vpll = vector<pll>;

#define rep(i, n) for(int i=0;i<(int)n;i++)
#define rep2(i, s, n) for(int i=(s);i<(int)n;i++)
int INF=1e9+7;

int main() {
  int N,M;
  cin >> N >> M;
  vi L(M),R(M),D(M);
  vector<vpii> v(N);
  rep(i,M) {
    cin >> L[i] >> R[i] >> D[i];
    L[i]--;R[i]--;
    v[L[i]].push_back(make_pair(R[i],D[i]));
    v[R[i]].push_back(make_pair(L[i],-D[i]));
  }
  
  vi x(N);
  bool flag=true;
  vector<bool> check(N);
  queue<int> que;
  rep(j,N) {
    if(!v[j].size()||check[j]) continue;
    que.push(L[j]);
    check[L[j]]=true;
    while(que.size()) {
      int q=que.front();
      que.pop();
      rep(i,v[q].size()) {
        if(check[v[q][i].first]) {
          if(x[v[q][i].first]!=x[q]+v[q][i].second) flag=false;
        }
        else {
          x[v[q][i].first]=x[q]+v[q][i].second;
          que.push(v[q][i].first);
          check[v[q][i].first]=true;
        }
      }
    }
    if(!flag) break;
  }
  
  if(flag) cout << "Yes" << endl;
  else cout << "No" << endl;
}