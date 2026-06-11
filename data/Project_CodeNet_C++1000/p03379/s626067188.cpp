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
  vi X(n);
  vi Y(n);
  rep(i,n){
    int x;
    cin >> x;
    X.at(i) = x;
    Y.at(i) = x;
  }
  sort(Y.begin(),Y.end());
  rep(i,n){
    if (X.at(i) < Y.at(n/2)) cout << Y.at(n/2) << endl;
    else cout << Y.at(n/2-1) << endl;
  }
  return 0;
}
