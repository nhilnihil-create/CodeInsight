#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i = (a); i <= (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main(){
  int a, b;
  cin >> a >> b;

  int count = 0;
  rep(i,a,b){
    auto isP = [](int n){
      ostringstream sout;
      sout << n;
      string s = sout.str();
      string b = s.substr(0, (s.size()+1)/2);
      string a = s.substr((s.size()-1)/2, string::npos);
      reverse(a.begin(), a.end());
      return b == a;
    };
    if (isP(i)){
      ++count;
    }
  }
  cout << count << endl;
  return 0;
}