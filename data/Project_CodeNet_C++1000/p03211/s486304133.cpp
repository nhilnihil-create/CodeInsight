#include <bits/stdc++.h>
using namespace std;

int main(){
 
  string s; cin >> s;
  int n = (int)s.length();
  int ptr1 = 0;
  int ptr2 = 2;
  int ans = INT_MAX;
  while(ptr2 < n){
    int sum = (s[ptr1] - '0')*100 + (s[ptr1 + 1] - '0')*10 + (s[ptr2] - '0'); 
    ans = min(abs(sum - 753),ans);
    ptr1++; ptr2++;
  }
  cout << ans << '\n';
}