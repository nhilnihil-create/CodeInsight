#include<bits/stdc++.h>
using namespace std;

int main(){
  int N, A, B;
  int P[3]={};
  cin >> N>> A >> B;
  for(int i=0; i<N; i++){
    int p; cin >> p;
    if(p<=A) P[0]++;
    else if(p<=B) P[1]++;
    else P[2]++;
  }
  cout << min(min(P[0],P[1]),P[2]) << endl;
  return 0;
}