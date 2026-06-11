#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};
 
int main(){
  string s;
  cin >> s;
  int k;
  cin >> k;
  set<string> st;
  for(int i=0; i<s.length(); i++){
    for(int j=1; j<=min(k, int(s.length())); j++){
      st.insert(s.substr(i,j));
    }
  }
  vector<string> v(st.begin(), st.end());
  cout << v[k-1] << endl;
  return 0;
}
