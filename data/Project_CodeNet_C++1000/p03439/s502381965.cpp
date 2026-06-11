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
const int INT_INF = 1 << 30;
#define MOD 1000000007LL
#define endl "\n"

int main(){
  ll N;
  cin >> N;
  ll left = 0, right = N-1;
  string ls, rs;
  string S;
  
  for(int tmp = 0; tmp < 20; tmp++){
    if(tmp == 0){
      
      cout << left << endl;
      cin >> S;
      if(S == "Vacant") break;
      ls = S;
    }
    else if(tmp == 1){
      cout  << right << endl;
      cin >> S;
      if(S == "Vacant") break;
      rs = S;
    }
    else{
      ll next = (right + left) / 2;
      cout << next << endl;
      cin >> S;
      if(S == "Vacant") break;
      if((next % 2 == 0 && S == ls) || (next % 2 != 0 && S == rs)) left = next;
      else right = next;
    }
  }
}