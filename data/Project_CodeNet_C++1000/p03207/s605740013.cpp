#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> p(n);
  int pay = 0;
  bool flag = true;
  for(int i = 0; i < n; i++){
    cin >> p[i];
  }
  int e = *max_element(p.begin(), p.end());
  for(int i = 0; i < n; i++){
    if(p[i] == e && flag) {pay += p[i] / 2; flag = false;}
    else pay += p[i];
  }
  cout << pay << endl;
}