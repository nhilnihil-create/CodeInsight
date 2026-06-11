#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};

 
int main(){
  string s, t;
  cin >> s >> t;
  int n = s.length();
  vector<int> sa(26, 0), ta(26, 0);
  vector<int> sv(n), tv(n);
  for(int i=0; i<n; i++){
    if(sa[s[i]-'a']){
      sv[i] = sa[s[i]-'a'];
    }else{
      sv[i] = i+1;
      sa[s[i]-'a'] = i+1;
    }
  }
  for(int i=0; i<n; i++){
    if(ta[t[i]-'a']){
      tv[i] = ta[t[i]-'a'];
    }else{
      tv[i] = i+1;
      ta[t[i]-'a'] = i+1;
    }
  }
  for(int i=0; i<n; i++){
    if(tv[i]!=sv[i]){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}
