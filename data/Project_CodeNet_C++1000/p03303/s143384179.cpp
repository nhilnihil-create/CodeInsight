#include<bits/stdc++.h>
using namespace std;

int main(){
  string S;
  int w;
  cin >> S >> w;
  int N=0;
  int L=S.size();
  while(N<L){
    cout << S.at(N);
    N+=w;
  }
}