#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i=0; i<n; i++){
    cin >> a.at(i);
  }
  int count = 0;
  map<int, int> b;
  for (int x: a){
    b[x] += 1;
    if (x < b[x]){
      count++;
    }
  }
  for (int x: a){
    if ( x > b[x]){
      count += b[x];
      b[x] = 0;
    }
  }
  cout << count << endl;
}