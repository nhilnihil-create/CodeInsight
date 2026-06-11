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
  ll N;
  cin >> N;
  vll A(N), B(N), C(N);
  vector<Pll> D(N);
  for(int i = 0; i < N; i++){
    cin >> A.at(i) >> B.at(i);
    C.at(i) = A.at(i) + B.at(i);
    D.at(i) = Pll(C.at(i), i);
  }
  sort(ALL(D), greater<Pll>());
  ll sum = 0;
  for(int i = 0; i < N; i++){
    int num = D.at(i).second;
    if(i%2==0){
      sum += A.at(num);
    }
    else sum -= B.at(num);
  }
  cout << sum << endl;
}