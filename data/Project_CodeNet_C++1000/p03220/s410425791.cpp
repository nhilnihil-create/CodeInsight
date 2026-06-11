#include<bits/stdc++.h>
using namespace std;

int main(){
  int n, t, a, place;
  cin >> n >> t >> a;
  
  double min = 10000000.0;
  vector<int> h(n);
  for(int i = 0; i<n; i++){
    cin >> h.at(i);
    if(abs(t - h.at(i) * 0.006 - a) < min){
      min = abs(t - h.at(i) * 0.006 - a);
      place = i;
    }
  }
  cout << place+1 << endl;
}