#include<bits/stdc++.h>
using namespace std;
int main(){
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  int a, b, c;
  int aa;
  set<int> st;
  for(c =0; c<=100000; c++){
    a = X - c;
    b = Y - c;
    st.insert(max(0, a)*A + max(0, b)*B + 2*c*C);
  }
 
  auto ans = st.begin();
  cout << *ans << endl;
  return 0;
}