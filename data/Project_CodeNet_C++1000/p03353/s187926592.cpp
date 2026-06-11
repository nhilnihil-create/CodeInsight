#include <bits/stdc++.h>
#define ALL(a)  (a).begin(),(a).end()
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<long long, long long> Pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
template <typename T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template <typename T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
const int INT_INF = 1LL << 30;

int main(){
  string s;
  cin >> s;
  int K;
  cin >> K;
  priority_queue<string, vector<string>, greater<string>> que;
  int ssize = s.size();
  int x = min(ssize, K);
  set<string> se;
  for(int k = 1; k <= x; k++){
    for(int i = 0; i+k-1 < s.size(); i++){
      string str = s.substr(i, k);
      if(!se.count(str)){
        que.push(str);
        se.insert(str);
      }
    }
  }
  for(int i = 0; i < K-1; i++){
    que.pop();
  }
  cout << que.top() << endl;

}
