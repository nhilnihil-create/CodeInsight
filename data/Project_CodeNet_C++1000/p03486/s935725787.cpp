#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, t;
  int ls, lt, flag=0;
  cin >> s >> t;
  sort(s.begin(), s.end());
  sort(t.rbegin(), t.rend());
  ls = s.size();
  lt = t.size();
  if(ls<lt){
    for(int i=0; i<ls; i++){
      if(s[i]>t[i]){
        cout << "No";
        return 0;
      }
      if(s[i]<t[i]){
        cout << "Yes";
        return 0;
      }
    }
    cout << "Yes";
    return 0;
  }
  if(ls>=lt){
    for(int i=0; i<lt; i++){
      if(s[i]>t[i]){
        cout << "No";
        return 0;
      }
      if(s[i]<t[i]){
        cout << "Yes";
        return 0;
      }
    }
    cout << "No";
    return 0;
  }
}