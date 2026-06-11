#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <cmath>
#include <iomanip>
using namespace std;
#define reps(i,s,n) for(int i = s; i < n; i++)
#define rep(i,n) reps(i,0,n)
#define Rreps(i,n,e) for(int i = n - 1; i >= e; --i)
#define Rrep(i,n) Rreps(i,n,0)
#define ALL(a) a.begin(), a.end()
#define endl "\n"
typedef long long ll;
#define traceV(v) for(auto x:v)cout<<x<<" ";cout<<endl
#define traceM(mp) for(auto x:mp)cout<<x.first<<" "<<x.second<<endl
#define MOD 1000000007

using Data = pair<ll, vector<int>>;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  // priority_queue の練習問題
  // https://drken1215.hatenablog.com/entry/2019/04/07/001000
  vector<int> N(3); rep(i,3) cin>>N[i];
  int K; cin>>K;
  vector<vector<ll>> v(3);
  rep(i,3) {
    v[i].resize(N[i]);
    rep(j,N[i]) cin>>v[i][j];
    sort(ALL(v[i]), greater<ll>());
  }

  priority_queue<Data> que;
  set<vector<int>> se;
  que.push(Data(v[0][0]+v[1][0]+v[2][0], vector<int>({0,0,0})));
  rep(i,K) {
    Data c = que.top(); que.pop();
    cout << c.first << endl;

    rep(j,3) {
      if(c.second[j] < N[j]-1) {
        ll sum = c.first - v[j][c.second[j]] + v[j][c.second[j]+1];
        vector<int> num = c.second; num[j]++;
        Data d = Data(sum, num);
        if(se.count(num)==0) se.insert(num), que.push(d);
      }
    }
  }

  return 0;
}
