#include <bits/stdc++.h>
using namespace std;
using pi = pair<string, int>;

int main() {
  int n; cin >> n;
  vector<pi> pa(n);
  for(int i=0; i < n; i++){
    string s;
    int p;
    cin >> s >> p;
    pa[i] = make_pair(s, -p);
  }
  
  vector<pi> temp = pa;
  sort(pa.begin(), pa.end());
  for(int i = 0; i < n; i++){
    string s; int sf;
    tie(s, sf) = pa[i];
    for(int j =0; j < n; j++) {
      if(pa[i] == temp[j]) cout << j+1 << endl;
    }
  }
  
  return 0;
}