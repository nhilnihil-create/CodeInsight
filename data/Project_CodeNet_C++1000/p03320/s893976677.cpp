#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<double, int> P;
const int INF = 1e16;

double S(int k) {
  int sum = 0;
  int t = k;
  while ( t ) {
    sum += t%10;
    t /= 10;
  }

  return (double)k/(double)sum;  
}

signed main() {
  int K;
  cin >> K;

  vector<int> candi; // snuke number の候補
  for ( int i = 1; i < 10; i++ ) candi.push_back(i);  

  int a = 10;
  while ( a < INF ) {
    for ( int i = 0; i < 1000; i++ ) {
      int b = a*i+a-1;      
      candi.push_back(b);      
    }
    a *= 10;
  }

  sort(candi.begin(), candi.end());
  candi.erase(unique(candi.begin(), candi.end()), candi.end());

  double mi = (double)INF;
  vector<int> snukes;  
  for ( int i = (int)candi.size()-1; i >= 0; i-- ) {
    if ( mi >= S(candi[i]) ) {      
      mi = S(candi[i]);      
      if ( i < (int)candi.size()-100 ) snukes.push_back(candi[i]);      
    }
  }  

  reverse(snukes.begin(), snukes.end());  
  for ( int i = 0; i < K; i++ ) {
    cout << snukes[i] << endl;
  }
  
  return 0;
}
