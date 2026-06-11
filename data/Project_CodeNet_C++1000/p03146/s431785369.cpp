#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  int s;
  cin >> s;

  set<int> st;  //すでに現れた数の集合

  int x = s;
  while (st.count(x) == 0){
    st.insert(x);
    if (x % 2 == 0){
      x /= 2;
    }else{
      x = x * 3 + 1;
    }
  }
  cout << st.size() + 1 << endl;
}
