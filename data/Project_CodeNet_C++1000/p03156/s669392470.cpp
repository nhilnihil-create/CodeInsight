#include<bits/stdc++.h>
using namespace std;
int main(){
  int n, a, b;
  cin >> n >> a >> b;
  int cnt1 = 0, cnt2 = 0, cnt3 = 0;
  for(int i = 0; i < n; i++){
    int p; cin >> p;
    if(p <= a) cnt1++;
    else if(p <= b) cnt2++;
    else cnt3++;    
  }
  cout << min({cnt1, cnt2, cnt3}) << endl;
  return 0;
}