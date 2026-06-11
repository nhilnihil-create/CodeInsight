#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
string s;
  cin >> s;
  int k=s.size();
  vector<char> pattern_a(k);
  vector<char> pattern_b(k);
  for(int i=0;i<k;i++){
  if(i%2 ==0)pattern_a[i]='1';
    else pattern_a[i]='0';
  
  }
    for(int i=0;i<k;i++){
  if(i%2 ==0)pattern_b[i]='0';
    else pattern_b[i]='1';
  
  }
  int cnt_a=0,cnt_b=0;
  for(int i=0;i<k;i++){
  if(s[i] != pattern_a[i])cnt_a++;
      if(s[i] != pattern_b[i])cnt_b++;
  
  }
  cout << min(cnt_a,cnt_b) <<endl;
}

