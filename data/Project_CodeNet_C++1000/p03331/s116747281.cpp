#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define REP2(i,x,n) for (int i = x; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);
static const int INF = 1e9+7;

int digitSum(int n){
  if(n < 10) return n;
  return digitSum(n/10) + n%10;
}

int digitSum(string s){
  int x = atoi(s.c_str());
  return digitSum(x);
}

int main() {
  int n;
  cin >> n;
  int minsum = INF;
  REP2(i,1,n){
    int a = i;
    int b = n - a;

    int sum = digitSum(a) + digitSum(b);

    minsum = min(sum, minsum);
  }


  cout << minsum << endl;
  return 0;
}
