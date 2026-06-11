#include <bits/stdc++.h>
#define P pair<int, int>

using namespace std;
const int INF=1e5;

int main(){
  int n, r, l, r_s, l_s;
  string s;
  cin >> n;
  cout << 0 << endl;
  cin >> s;
  if(s=="Vacant")return 0;
  r = 0;
  r_s = (s=="Male"?0:1);
  cout << n-1 << endl;
  cin >> s;
  if(s=="Vacant")return 0;
  l = n-1;
  l_s = (s=="Male"?0:1);
  for(int i=0;i<18;i++){
    int mid = (l+r)/2, mid_s;
    cout << mid << endl;
    cin >> s;
    if(s=="Vacant")return 0;
    mid_s = (s=="Male"?0:1);
    if(mid_s^r_s^((mid-r)%2)){
      l=mid;
      l_s=mid_s;
    }
    else{
      r=mid;
      r_s=mid_s;
    }
  }
  return 0;
}

