#include <bits/stdc++.h>
#include <set>
using namespace std;
#define rep(i,n) for(int i; i<(int)(n); i++)

int main() {
  int N;
  cin >> N;
  set<char>st;
  rep(i, N) {
    char h;
    cin >> h;
    st.insert(h);
  }
  if (st.size() == 3) cout << "Three" << endl;
  else if(st.size() == 4) cout << "Four" << endl;
}