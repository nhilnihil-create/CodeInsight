#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int cntb = 0, cnta = 0, both = 0, ab = 0;
  for(int i = 0; i < n; i++){
    string s;
    cin >> s;
    int l = s.size();
    for(int j = 0; j < l-1; j++){
      if(s.at(j) == 'A' && s.at(j+1) == 'B') ab++;
    }
    if(s.at(0) == 'B'){
      if(s.at(l-1) == 'A') both++;
      else cntb++;
    }
    else if(s.at(l-1) == 'A') cnta++;
  }
  
  if(both == 0) ab += min(cnta, cntb);
  else if(cnta + cntb == 0) ab += both - 1;
  else ab += min(cnta, cntb) + both;
  cout << ab << endl;
}