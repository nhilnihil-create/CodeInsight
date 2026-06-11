#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int q=1;
  cin >> q;
  vector<int> l(q), r(q);
  rep(i,q){
    l.at(i) = 3; r.at(i) = 7;
    cin >> l.at(i) >> r.at(i);
  }

  vector<bool> prime(100001,true);
  prime.at(0) = false;
  prime.at(1) = false;
  int rootN = (int)sqrt(100000);
  int i=2;
  while(i<=rootN){
    if(prime.at(i)){
      int mul = 2*i;
      while(mul<=100000){
        prime.at(mul) = false;
        mul += i;
      }
    }
    i++;
  }

  vector<int> s(100002,0);
  i=3;
  while(i<=100000){
    s.at(i+2) = s.at(i);
    if( (prime.at(i)) && (prime.at((i+1)/2)) )  s.at(i+2)++;
    i += 2;
  }

  int ans=0;
  rep(i,q){
    ans = s.at(r.at(i)+2)-s.at(l.at(i));
    cout << ans << endl;
  }
}