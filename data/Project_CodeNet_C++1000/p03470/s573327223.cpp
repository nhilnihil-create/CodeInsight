#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, count=1;
  cin >> N;
  vector<int> d_i(N);
  
  for (int i=0;i<N;i++)
    cin >> d_i.at(i);
  sort(d_i.begin(),d_i.end());
  int minimum = d_i.at(0);
  
  for (int i=1;i<N;i++){
    if ( d_i.at(i) > d_i.at(i-1) )
      count++;
  }
  
  cout << count << endl;
}     