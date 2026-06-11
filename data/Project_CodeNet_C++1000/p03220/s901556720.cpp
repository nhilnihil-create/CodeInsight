#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, T, A;
  cin >> N >> T >> A;
  vector<int>H(N);
  for(int i=0; i<N; i++)cin >> H.at(i);
  
  double kion=A-(T-H.at(0)*0.006);
  int ans =1;
  
  for(int i=0; i<N; i++){
    double sa = A-(T-H.at(i)*0.006);
    if(kion*kion>sa*sa){
      kion = sa;
      ans = i+1;
    }
  }
  
  cout << ans << endl;
}