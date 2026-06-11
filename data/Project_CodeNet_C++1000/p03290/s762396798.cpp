#include <bits/stdc++.h>
using namespace std;

int main(){
  int d, g; cin >> d >> g;
  vector<int> p(d);
  vector<int> c(d);
  
  for (int i=0; i<d; i++){
    cin >> p.at(i) >> c.at(i);
  }
  
  int ans = 10000;
  
  for (int tmp=0; tmp < (1 << d); tmp++){
    int count = 0;
    int sum = 0;
    int max = 0;
    for (int i=0; i < d; i++){
      if (tmp >> i & 1){
        sum += (i+1)*100*p.at(i) + c.at(i);
        count += p.at(i);
      }
      else {
        max = i;
      }
    }
    if (sum < g) {
      int t = 100*(max+1);
      if ((g-sum)%t == 0){
        if ((g-sum+t)/t > p.at(max)) {continue;}
        count += ((g-sum)/t);
      }
      else {
        if ((g-sum+2*t)/t > p.at(max)) {continue;}
        count += ((g-sum+t)/t);
      }
    }
    ans = min(ans, count);
  }
  cout << ans << endl;
}