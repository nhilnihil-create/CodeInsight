#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, T, A;
  cin >> N >> T >> A;
  
  vector <int> H(N);
  
  double min = 10000000;
  int best;
  
  for (int i=0; i<N; i++){
    cin >> H[i];
    double Ti = T - H[i]*0.006;
    
    if( Ti-A >= 0 && Ti-A < min){
      min = Ti-A;
      best = i+1;
    }
    if( Ti-A < 0 && A-Ti < min){
      min = A-Ti;
      best = i+1;
    }
  }
  cout << best << endl;
    

   
}