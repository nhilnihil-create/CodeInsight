#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,X,count = 0, min_m = 10000;
  cin >> N >> X;
  vector<int> m(N);
  for(int i = 0; i< N; i++){
    cin >> m.at(i);
    int a = m.at(i);
    X = X - a;
    count++;
    if(min_m > a){
      min_m = a;
    }
  }
  count = count + (X/min_m);
  cout << count << endl;
}