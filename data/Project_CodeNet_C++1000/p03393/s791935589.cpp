#include <bits/stdc++.h>
#include <math.h>
#include <cmath>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int> ;
using vi = vector<int> ;
using vll = vector<long long>;

int main(){
  string s; cin >> s;
  int n = s.size();
  if(n < 26){
    bool fin = false;
    string t;
    for(int i = 0; i < 26; i++){
      for(int j = 0; j < n; j++){
        if(s[j] == 'a' + i){break;}
        if(j == n-1){t.push_back('a' + i); fin = true;}
      }
      if(fin){break;}
    }
    cout << s+t << endl;
  }
  else{
    bool fin = false;
    string t;
    char c = s[n-1];
    vector<char> v(1, c);
    for(int i = n-2; i >= 0; i--){
      if((int)s[i] < (int)c){t = s.substr(0, i+1); fin = true; break;}
      else{v.push_back(s[i]); c = s[i];}
    }
    if(!fin){cout << -1 << endl;}
    else{
      auto itr = lower_bound(v.begin(), v.end(), t[t.size()-1]);
      t[t.size()-1] = *itr;
      cout << t << endl;
      }
  }
}
