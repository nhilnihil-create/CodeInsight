#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

bool is_parindrome(int tested){
  int tot = 0;
  for (int i=0;i<=26;i++) {
    if (((tested >> i) & 1) == 1)
      tot++;
  }
  if (tot > 1)
    return(false);
  else
    return(true);
}

int n, bit[200001] = {};
int split[(1<<26)] = {};

int main(){
  string s;
  cin >> s;
  n = s.length();
  for (int i=0;i<(1<<26);i++) {
    split[i] = 200001;
  }
  bit[0] = 1 << (s[0] - 97);
  split[bit[0]] = 1;
  for (int i=1;i<n;i++) {
    int ascii = s[i] - 97;
    int split_tmp = n;
    int split_idx;
    bit[i] = 1 << ascii;
    bit[i] = bit[i] ^ bit[i-1];
    if (is_parindrome(bit[i])) {
      split_tmp = 0;
    } else {
      for (int k=0;k<26;k++) {
	if (split_tmp > split[((1 << k) ^ bit[i])]) {
	    split_tmp = split[((1 << k) ^ bit[i])];
	}
      }
    }
    split[bit[i]] = split_tmp + 1;
    
  }
  cout << split[bit[n-1]] << endl;
  return 0;
}
