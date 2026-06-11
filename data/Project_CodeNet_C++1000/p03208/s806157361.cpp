#include<bits/stdc++.h>
using namespace std;

int main(){
  int N, K;
  cin >> N >> K;
  vector<int> h(N);
  for(int i = 0; i < N; i++){
    cin >> h.at(i);
  }
  sort(h.begin(), h.end());
  int dif = 2147483647;
  for(int i = K-1; i < N; i++){
    if(h.at(i) - h.at(i-K+1) < dif) dif = h.at(i) - h.at(i-K+1);
  }
  cout << dif << endl;
}