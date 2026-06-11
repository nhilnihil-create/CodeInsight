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
  int N;
  cin >> N;
  vi A(N);
  for(int i = 0; i < N; i++){
    cin >> A.at(i);
    A.at(i) -= i+1;
  }
  sort(ALL(A));
  int x = N/2;
  int y = (N-1)/2;
  ll ans1 = 0, ans2 = 0;
  for(int i = 0; i < N; i++){
    ans1 += abs((ll)A.at(i) - (ll)A.at(x));
    ans2 += abs((ll)A.at(i) - (ll)A.at(y));
  }
  cout << min(ans1, ans2) <<endl;

}