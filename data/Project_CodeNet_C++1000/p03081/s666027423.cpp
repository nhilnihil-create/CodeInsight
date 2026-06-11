#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, Q; cin >> N >> Q;
  string s; cin >> s;
  vector<char> t(Q), d(Q);
  for(int i = 0; i < Q; i++) cin >> t[i] >> d[i];
  int left = -1, right = N;
  while(right - left > 1){
    int mid = (right + left) / 2, mid1 = mid;
    for(int i = 0; i < Q; i++){
      if(t[i] == s[mid] && d[i] == 'L') mid--;
      if(t[i] == s[mid] && d[i] == 'R') mid++;
      if(mid == N || mid == -1) break;
    }
    if(mid == -1) left = mid1;
    else right = mid1;
  }
  int ans_left = left;
  left = -1, right = N;
  while(right - left > 1){
    int mid = (right + left) / 2, mid1 = mid;
    for(int i = 0; i < Q; i++){
      if(t[i] == s[mid] && d[i] == 'L') mid--;
      if(t[i] == s[mid] && d[i] == 'R') mid++;
      if(mid == N || mid == -1) break;
    }
    if(mid == N) right = mid1;
    else left = mid1;
  }
  int ans_right = right;
  cout << ans_right - ans_left - 1 << endl;
}
