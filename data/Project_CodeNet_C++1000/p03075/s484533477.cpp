#include <bits/stdc++.h>
using namespace std;

int main(){
  vector<int> ant(5,0);
  for(int i=0; i<5; i++) cin>>ant[i];
  sort(ant.begin(),ant.end());
  int k; cin>>k;
  if(k>=ant[4]-ant[0]) cout << "Yay!" << endl;
  else cout << ":(" << endl;
}