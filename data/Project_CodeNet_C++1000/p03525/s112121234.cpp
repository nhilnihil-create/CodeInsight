#include <bits/stdc++.h>

using namespace std;

int main(){
  int n, d, mn=12;
  map<int, int> mp;
  cin >> n;
  for(int i=0;i<n;i++){
    cin >> d;
    mn = min(mn, d);
    mp[d]++;
  }
  int mxl=0, mxr=0;
  for(auto p: mp){
    if(p.second==1){
      if(mxl<=mxr){
        mn = min(mn, p.first-mxl);
        mxl = p.first;
      }
      else{
        mn = min(mn, p.first-mxr);
        mxr = p.first;
      }
    }
    else if(p.second==2){
      mn = min({mn, p.first-mxl, p.first-mxr});
      mxl=p.first;
      mxr=p.first;
    }
    else{
      mn = 0;
    }
  }
  mn = min(mn, (12-mxl)+(12-mxr));
  cout << mn << endl;
}

