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

template<typename T>
bool is_prime(T n){
  for(T i = 2; i * i <= n; i++){
    if(n % i == 0) return false;
  }
  return n != 1;
}

int main(){
  ll N;
  cin >> N;
  vvll prime(5, vll(0));
  prime.at(2).push_back(2);
  for(int i = 3; i <= 55555; i+=2){
    if(is_prime(i)) prime.at(i%5).push_back(i);
  }
  for(int i = 0; i < N; i++){
    cout << prime.at(1).at(i);
    if(i == N-1) cout << endl;
    else cout << ' ';
  }
}