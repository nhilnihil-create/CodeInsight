#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  cout << 0 << endl;
  string s;
  cin >> s;
  if(s == "Vacant") return 0;
  bool f0 = true;
  if(s == "Male") f0 = false;
  int l=0, r=n;
  while(1){
    int mid = (l+r)/2;
    cout << mid << endl;
    cin >> s;
    if(s == "Vacant") return 0;
    bool fmid = true;
    if(s == "Male") fmid = false;
    if(f0 == fmid && mid%2 == 0){
      l = mid;
    }
    else if(f0 != fmid && mid%2 == 1){
      l = mid;
    }else{
      r = mid;
    }
  }
}