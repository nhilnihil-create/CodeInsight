#include<bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin >> S;
  int L=S.size();
  for(int i=0; i<L-8; i++){
    cout << S.at(i);
  }
  cout << endl;
}