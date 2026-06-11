#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,T,A;
  cin >> N >> T >> A;
  
  pair<int,int>t[N];
  for(int i=0;i<N;++i){
    int H;
    cin >> H;
    int diff = abs(1000*A-(1000*T-H*6));
    
    t[i] = make_pair(diff,i+1);
  }
  
  sort(t,t+N);
  
  cout << t[0].second << endl;
  return 0;
}