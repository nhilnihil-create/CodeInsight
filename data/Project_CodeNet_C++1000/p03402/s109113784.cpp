#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define ALL(a)  (a).begin(),(a).end()
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int a, b;
  cin >> a >> b;
  cout << "100 100" << endl;
  rep(i,50){
    rep(i, 25){
      if(a > 1){
        cout << ".#";
        --a;
      }else{
        cout << "##";
      }
    }
    rep(i, 25){
      if(b > 1){
        cout << ".#";
        --b;
      }else{
        cout << "..";
      }
    }
    cout << endl;
    rep(i, 50) cout << "#";
    rep(i, 50) cout << ".";
    cout << endl;
  }
}
