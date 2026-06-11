#include <bits/stdc++.h>
using namespace std;

int main(){
  int S;
  string w;
  cin >> w >> S;
  int Q = w.size();
  for(int i=0; i<Q; i+=S){
    cout << w[i];
  }
}
