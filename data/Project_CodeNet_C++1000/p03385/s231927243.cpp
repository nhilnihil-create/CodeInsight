#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;

int main() {
  set<char> s;
  rep(i,3){
    char a; cin >> a;
    s.insert(a);
  }
  if(s.size() == 3){
    cout << "Yes";
  }
  else{
    cout << "No";
  }
}
