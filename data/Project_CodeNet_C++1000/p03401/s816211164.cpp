#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<n; i++)
#define REP(i,x,n) for (int i=x; i<n; i++)
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;

int main(){
  int n;
  cin >> n;
  vi a(n+2);
  a.at(0) = 0;
  a.at(n+1) = 0;
  int sum = 0;
  REP(i,1,n+1){
    cin >> a.at(i);
  }
  rep(i,n+1){
    sum += abs(a.at(i+1) - a.at(i));
  }
  REP(i,1,n+1){
    if ((a.at(i) > a.at(i-1) && a.at(i) < a.at(i+1)) ||
     (a.at(i) < a.at(i-1) && a.at(i) > a.at(i+1))){
      cout << sum << endl;
    }
    else {
      cout << sum - abs(a.at(i) - a.at(i-1)) - abs(a.at(i+1) - a.at(i)) + abs(a.at(i+1) - a.at(i-1)) << endl;;
    }
  }
  return 0;
}
