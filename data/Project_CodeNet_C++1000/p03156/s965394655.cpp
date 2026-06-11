#include<bits/stdc++.h>
using namespace std;
int main(){
  int n, a, b;
  cin >> n >> a >> b;
  vector<int> low, med, hig;
  for(int i = 0; i < n; i++){
    int p;
    cin >> p;
    if(p <= a) low.push_back(p);
    else if(b+1 <= p) hig.push_back(p);
    else med.push_back(p);
  }
  cout << min({low.size(), med.size(), hig.size()}) << endl;
  return 0;
}