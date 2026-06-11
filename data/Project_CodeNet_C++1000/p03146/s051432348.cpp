#include<bits/stdc++.h>
using namespace std;
int main(){
  set<int> a;
  int s; cin >> s;
  a.insert(s);
  vector<int> suuretu;
  suuretu.push_back(s);
  while(1){
    if(s % 2 == 0) s /=2;
    else		   s = 3 * s + 1;
    if(a.count(s)){
      suuretu.push_back(s);
      break;
    }
    a.insert(s);
    suuretu.push_back(s);
  }
  cout << suuretu.size();
}