#include<bits/stdc++.h>

using namespace std;

int A,B,K;
vector<int> N;


void input(){
  cin >> A >> B >> K;
}

void solve(){
  int m=min(A,B);
  for(int i=1;i<=m;i++){
    if(A%i==0 && B%i==0){
      //      cout << i << endl;
      N.push_back(i);
    }
  }
}

int main(){
  input();
  solve();
  /*  for(auto ax:N){
    cout << ax << endl;
  }
  */
  sort(N.begin(),N.end(),greater<int>());
  /*  for(auto ax:N){
    cout << ax << endl;
  }
  */
  cout << N[K-1] << endl;
  return 0;
}
