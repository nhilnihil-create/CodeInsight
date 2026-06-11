#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main() {
  
  int N;
  cin >> N;

  vector<double> a(N);
  double sum = 0;
  for(int i = 0;i < N;i++) {
    cin >> a.at(i);
    sum += a.at(i);
  }

  sum /= N;
  double mini = 10000,ans = 0;
  for(int i = 0;i < N;i++) {
    double d = abs(a.at(i)-sum);
    if(mini > d) {
      mini = d;
      ans = i;
    }
  }

  cout << ans << endl;
}

