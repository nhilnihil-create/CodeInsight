#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, P=0, W=0, G=0, Y=0;
  cin >> N;
  for(int i=0;i<N;i++){
    string S;
    cin >> S;
    if(S=="P") P++;
    if(S=="W") W++;
    if(S=="G") G++;
    if(S=="Y") Y++;
  }
  int j=0;
  if(P>0) j++;
  if(W>0) j++;
  if(G>0) j++;
  if(Y>0) j++;
  if(j<4) cout << "Three" << endl; else cout << "Four" << endl;  
}