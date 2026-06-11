#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> vn(n);
  for(int i=0; i<n; ++i) cin >> vn[i];
  map<int, int> mp1, mp2;
  int mxn11 =0, mxn12 =0, mp1mx =0;
  for(int i=0; i<n; i += 2){
    ++mp1[vn[i]];
    int x = mp1[vn[i]];
    if(x > mxn11){
      int y = mxn11;
      mxn11 = x;
      if(mp1mx != vn[i]){
        mp1mx = vn[i];
        if(y > mxn12) mxn12 = y;
      }
    }
    else if(x > mxn12) mxn12 = x;
  }
  int mxn21 =0, mxn22 =0, mp2mx =0;
  for(int i=1; i<n; i += 2){
    ++mp2[vn[i]];
    int x = mp2[vn[i]];
    if(x > mxn21){
      int y = mxn21;
      mxn21 = x;
      if(mp2mx != vn[i]){
        mp2mx = vn[i];
        if(y > mxn22) mxn22 = y;
      }
    }
    else if(x > mxn22) mxn22 = x;
  }
  if(mp1mx != mp2mx) cout << n -mxn11 -mxn21 << endl;
  else cout << n - max(mxn12 +mxn21, mxn11 +mxn22) << endl;
}