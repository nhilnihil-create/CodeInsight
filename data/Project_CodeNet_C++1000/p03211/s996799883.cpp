#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin >> S;
  int A=S.size(),min_distance=1000;
  for(int i=0;i<A-2;i++){
    string T=S.substr(i,3);
    int B=stoi(T);
    min_distance=min(min_distance,abs(B-753));
  }
  cout << min_distance << endl;
}
