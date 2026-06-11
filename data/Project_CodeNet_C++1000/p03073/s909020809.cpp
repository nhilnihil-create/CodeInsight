#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(I, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;

int main() {
  string s,s1,s2;
  cin >> s;
  
  int n = s.size();
  REP(i,n){
    if(i % 2 == 0){
      s1.push_back('0');
      s2.push_back('1');
    }
    else{
      s2.push_back('0');
      s1.push_back('1');
    }
  }
  
  int sum1 = 0,sum2 = 0;;
  REP(i,n){
    if(s[i] == s1[i]) sum1++;
    else if(s[i] == s2[i]) sum2++;
  }
  int ans = min(sum1,sum2);
    
  
  cout << ans << endl;
}