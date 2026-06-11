#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int N;
  cin >> N;
  string s;
  rep(i,N){
    cin >> s;
    if(s == "Y"){
      cout << "Four" << endl;
      return 0;
    }
  }
  cout << "Three" << endl;

}


