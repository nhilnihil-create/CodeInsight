#include <bits/stdc++.h>
#define ALL(a)  (a).begin(),(a).end()
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
  ll N, K;
  cin >> N >> K;
  string S;
  cin >> S;
  vector<P> box(0);
  int counter = 1;
  for(int i = 0; i < N-1; i++){
    if(S.at(i) != S.at(i+1)){
      box.push_back(P(S.at(i), counter));
      counter = 1;
    }
    else{
      counter++;
    }
  }
  box.push_back(P(S.at(N-1), counter));

  ll ans = 0;
  ll now = 0;
  int right = 0;
  int zero = 0;
  for(int left = 0; left < box.size(); left++){
    if(left > 0){
      if(box.at(left-1).first == '0') zero--;
      now -= box.at(left-1).second;
    }

    while(right < box.size()){
      if(box.at(right).first == '0' && zero >= K) break;
      if(box.at(right).first == '0') zero++;
      now += box.at(right).second;
      right++;
    }
    chmax(ans, now);
  }
  cout << ans << endl;
}