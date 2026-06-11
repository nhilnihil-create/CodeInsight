#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w;
  cin >> h >> w;
  
  string s_prv, s_mid, s_nxt;
  s_prv = "";
  for (int i = 0; i < w; i++){
    s_prv += ".";
  }
  cin >> s_mid;

  for (int i = 0; i < h; i++){
    if (i < h) {
      cin >> s_nxt;
    }
    for (int j = 0; j < w; j++){
      if (s_mid.at(j) == '.') {
        int ans = 0;
        if (j>0) {
          if (s_mid.at(j-1) == '#'){
            ans += 1; }}
        if (j<w-1) {
          if (s_mid.at(j+1) == '#'){
            ans += 1; }}
        if (i>0) {
          if (s_prv.at(j) == '#'){
            ans += 1; }}
        if (i<h-1) {
          if (s_nxt.at(j) == '#'){
            ans += 1; }}
        if (j>0 && i>0) {
          if (s_prv.at(j-1) == '#'){
            ans += 1; }}
        if (j>0 && i<h-1) {
          if (s_nxt.at(j-1) == '#'){
            ans += 1; }}
        if (j<w-1 && i>0) {
          if (s_prv.at(j+1) == '#'){
            ans += 1; }}
        if (j<w-1 && i<h-1) {
          if (s_nxt.at(j+1) == '#'){
            ans += 1; }}
        cout << ans;
      } else {
        cout << '#';
      }
    }
    cout << endl;
    s_prv = s_mid;
    s_mid = s_nxt;
  }
}
