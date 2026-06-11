#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(){
  int N;
  string A, B, C;
  cin >> N >> A >> B >> C;
  vector<int> match(N);
  for(int i=0; i<N; i++){
    if(A.at(i)!=B.at(i)) match.at(i)++;
    if(B.at(i)!=C.at(i)) match.at(i)++;
    if(C.at(i)!=A.at(i)) match.at(i)++;
    if(match.at(i)>=2) match.at(i)--;
  }
  int ans=0;
  for(int i=0; i<N; i++) ans+=match.at(i);
  cout << ans << endl;
}