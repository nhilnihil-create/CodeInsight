#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < int(n); i++)
#define vi vector<int>
#define all(x) (x).begin(),(x).end()
#define INF (1<<30)-1
using ll = long long;
using namespace std;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T &a, const T &b){ if(a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b){ if(b<a) { a=b; return 1; } return 0; }

int main(){
  cin.tie(0), ios::sync_with_stdio(false);
  string S,T; cin >> S >> T;
  map<char,int> s,t;
  rep(i,S.size()){
    s[S[i]]++;
    t[T[i]]++;
  }
  vi cnt_s,cnt_t;
  for(auto x : s) cnt_s.push_back(x.second);
  for(auto x : t) cnt_t.push_back(x.second);
  sort(all(cnt_s));
  sort(all(cnt_t));
  if(cnt_s.size() != cnt_t.size()){
    cout << "No";
    return 0;
  }else{
    rep(i,cnt_t.size()){
      if(cnt_s[i] != cnt_t[i]){
        cout << "No";
        return 0;
      }
    }
  }
  cout << "Yes";
  cout << "\n";
  return 0;
}
