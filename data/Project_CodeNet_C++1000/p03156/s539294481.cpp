#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int n, a, b;
  cin >> n >> a >> b;
  
  vector<int> p(n);
  for(int i = 0; i < n; i++){
    cin >> p[i];
  }
  
  int one=0, two=0, three=0;
  
  for(int i = 0; i < n; i++){
    if(p[i] <= a) one++;
    else if(a + 1 <= p[i] && p[i] <= b) two++;
    else if(p[i] >= b+1) three++;
  }
  
  cout << min({one, two, three});
   
}
