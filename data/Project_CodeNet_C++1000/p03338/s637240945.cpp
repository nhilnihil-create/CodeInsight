#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> a(s.size());
  int ans = 0;
  for(int i = 0; i < n; i++){
    int count = 0;
    for(char c = 'a'; c <= 'z'; c++){
      bool left = false,right = false;
      for(int j = 0; j < i; j++){
        if(s[j] == c) left = true;
      }
      for(int j = i; j < n; j++){
        if(s[j] == c) right = true;
      }
      if(left && right) count++;
    }
    ans = max(ans,count);
  }
  cout << ans << endl;
}