#include <bits/stdc++.h>
using namespace std;
void hoge(int n, int k, int sm[], int lg[], int s, int l, bool haszero) {
  int z = haszero ? 1 : 0;
  int minvalue = INT_MAX;
  if (k <= s + z) {
    minvalue = sm[k-1-z];
  }
  if (k <= l + z) {
    minvalue = min(minvalue, lg[k-1-z]);
  }
  int startvalue = 0;
  if (k > l+z) {
    startvalue = k-l+z-1;
  }
  for (int i = 0; i < min(s,n-k+1); i++) {
    minvalue = min(minvalue, sm[startvalue+i]*2+lg[k-z-startvalue-i-2]);
    minvalue = min(minvalue, sm[startvalue+i]+lg[k-z-startvalue-i-2]*2);
  }
  cout << minvalue << endl;
}
int main() {
  int n, k, s, l;
  int sm[100000];
  bool haszero = false;
  int lg[100000];
  s=l=0;
  
  cin >> n >> k;
  for(int i =0; i < n; i++) {
    int v;
    cin >> v;
    if (v < 0) {
      sm[s++] = v;
    } else if (v == 0) {
      haszero = true;
    }
    else {
      lg[l++] = v;
    }
  }
  int sm2[100000];
  for(int i = 0; i < s; i++) {
    sm2[i]=sm[s-1-i] * -1;
  }
  if (s < l) {
    hoge(n, k, sm2, lg, s, l, haszero);
  } else {
    hoge(n, k, lg, sm2, l, s, haszero);
  }
  return 0;
}