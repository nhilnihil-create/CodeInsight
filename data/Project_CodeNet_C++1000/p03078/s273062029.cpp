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
  ll X, Y, Z, K;
  cin >> X >> Y >> Z >> K;
  vll A(X), B(Y), C(Z);
  for(int i = 0; i < X; i++){
    cin >> A.at(i);
  }
  for(int i = 0; i < Y; i++){
    cin >> B.at(i);
  }
  for(int i = 0; i < Z; i++){
    cin >> C.at(i);
  }
  sort(ALL(A), greater<ll>()); sort(ALL(B), greater<ll>()); sort(ALL(C), greater<ll>());
  ll sum = A.at(0) + B.at(0) + C.at(0);
  priority_queue<ll, vector<ll>, greater<ll>> bc;
  bool flag = false;
  for(int i = 0; i < Y; i++){
    for(int j = 0; j < Z; j++){
      ll num = B.at(0) - B.at(i) + C.at(0) - C.at(j);
      bc.push(num);
    }
  }
  priority_queue<ll, vector<ll>, greater<ll>> que;
  for(int i = 0; i < 3000; i++){
    if(bc.empty()) break;
    ll x = bc.top(); bc.pop();
    for(int j = 0; j < X; j++){
      ll num = A.at(0) - A.at(j) + x;
      que.push(num);
    }
  }
  for(int i = 0; i < K; i++){
    ll num = que.top(); que.pop();
    cout << sum - num << endl;
  }
}