#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  vector<int> a(n+2);
  a.at(0) = 0;
  for(int i=1;i<n+1;i++){
    cin >> a.at(i);
  }
  a.at(n+1) = 0;
  
  ll dist = 0;
  for(int i=1;i<n+2;i++){
    dist += abs(a.at(i) - a.at(i-1));
  }
  
  //cout << dist << endl;
  for(int i=1;i<n+1;i++){
    cout << dist + abs(a.at(i+1) - a.at(i-1)) - (abs(a.at(i+1) - a.at(i)) + abs(a.at(i) - a.at(i-1))) << endl; 
  }
  
  return(0);
}