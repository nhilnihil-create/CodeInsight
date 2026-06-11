#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  int N, T;
  cin >> N >> T;

  vector<int> c(N);
  vector<int> t(N);

  for (int i = 0; i < N; i++){
    cin >> c.at(i) >> t.at(i);
  }

  int min = 999999;
  for (int i = 0; i < N; i++)
  {
    if (T >= t.at(i) && min > c.at(i)) min = c.at(i);
  }

  if (min == 999999){
    cout << "TLE" << endl;
  }
  else
  {
    cout << min << endl;  
  }
  
  
  
}