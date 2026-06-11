#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int t=0, tf=0, b=0, bf=0;
  
  cin >> t >> tf >> b >> bf;
  
  int train = min(t, tf);
  int bus = min(b, bf);
  
  int sum = train+bus;
  
  cout << sum << endl;
  
}