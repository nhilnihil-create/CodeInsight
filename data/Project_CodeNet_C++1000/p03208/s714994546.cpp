#include<bits/stdc++.h>
using namespace std;

int main(){
  int N, K;
  cin >> N >> K;
  vector<int> H(N);
  for(int i=0; i<N; i++){
    cin >> H.at(i);
  }
  sort(H.begin(), H.end());
  int Ans=1000000000;
  for(int i=0; i<N-K+1; i++){
    Ans=min(Ans, H.at(i+K-1)-H.at(i));
  }
  cout << Ans << endl;
}