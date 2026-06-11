#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool check(int i, string& s, vector<char>&t, vector<char>&d, int c){
  for(int j=0; j<t.size(); j++){
    if(s[i]==t[j]){
      if(d[j]=='R')i++;
      else i--;
    }
  }
  return i==c;
}

int main(){
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  s.insert(s.begin(), '#');
  vector<char>t(q), d(q);
  s.push_back('#');
  for(int i=0; i<q; i++)cin >> t[i] >> d[i];
  int ok1=0, ng1=n+1;
  while(ng1-ok1>1){
    int mid=(ok1+ng1)/2;
    if(check(mid, s, t, d, 0)){
      ok1=mid;
    }
    else {
      ng1=mid;
    }
  }
  int ok2=n+1, ng2=0;
  while(ok2-ng2>1){
    int mid=(ok2+ng2)/2;
    if(check(mid, s, t, d, n+1)){
      ok2=mid;
    }
    else {
      ng2=mid;
    }
  }
  cout << ng2-ok1;
  cerr << ok1 << endl;
  cerr << ng1 << endl;
  cerr << ng2 << endl;
  cerr << ok2 << endl;
  return 0;
}
