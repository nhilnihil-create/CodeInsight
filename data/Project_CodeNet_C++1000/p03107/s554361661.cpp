#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using ll = long long;
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n-1; i >= 0; i--)
using namespace std;

int main(){
  string s;
  cin >> s;
  int n = s.size();
  vector<char> st;
  rep(i, n){
    if (st.empty()){
      st.push_back(s[i]);
    }
    else{
      if (st.back() != s[i]) st.pop_back();
      else st.push_back(s[i]);
    }
  }
  cout << n - st.size() << endl;
  
  return 0;
}