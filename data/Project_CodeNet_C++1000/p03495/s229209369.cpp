#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,K;
  cin >> N >> K;
  vector<int> A(N);
  for(int i=0;i<N;i++){
    cin >> A.at(i);
  }
  vector<int> kosuu(N,0);
  for(int i=0;i<N;i++){
    kosuu.at(A.at(i)-1)++;
  }
  sort(kosuu.begin(),kosuu.end());
  reverse(kosuu.begin(),kosuu.end());
  int goukei=0;
  for(int i=0;i<K;i++){
    goukei+=kosuu.at(i);
  }
  cout << N-goukei << endl;
}