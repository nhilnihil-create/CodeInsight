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
#define MOD 1000000007LL

int main(){
  ll N, M;
  cin >> N >> M;
  vll A(M);
  vi num = {INT_INF, 2, 5, 5, 4, 5, 6, 3, 7, 6};
  vector<pair<char, int>> box(0);
  vi dp(10100, -1*INT_INF);
  vector<string> str(10100, "");
  for(int i = 0; i < M; i++){
    int A;
    cin >> A;
    box.push_back(pair<char, int>(A + '0', num.at(A)));
    dp.at(num.at(A)) = 1;
    str.at(num.at(A)) = (char)(A + '0');
  }
  for(int i = 1; i <= N; i++){ //合計の本数
    for(int j = 0; j < box.size(); j++){
      //末尾にbox.at(i).firstを付け加える
      int n = box.at(j).second; //増える本数
      if(i-n < 0) continue;
      if(dp.at(i-n)+1 > dp.at(i)){ //桁を増やせる
        dp.at(i) = dp.at(i-n) + 1;
        str.at(i) = str.at(i-n) + box.at(j).first;
      }
      else if(dp.at(i-n)+1 == dp.at(i)){
        string s1 = str.at(i);
        string s2 = str.at(i-n) + box.at(j).first;
        sort(ALL(s1), greater<char>()); sort(ALL(s2), greater<char>());
        if(s1 > s2) str.at(i) = s1;
        else str.at(i) = s2;

      }
    }
  }
  sort(ALL(str.at(N)), greater<char>());
  cout << str.at(N) << endl;
}