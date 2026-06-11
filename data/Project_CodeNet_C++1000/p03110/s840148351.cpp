#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  double sum = 0.0;
  rep(i, n){
  	double x;
    string u;
    cin >> x >> u;
    if(u == "JPY"){
    	sum += x;
    }else{
    	sum += x * 380000;
    }
  }
  cout << sum << endl;
  return 0;
}