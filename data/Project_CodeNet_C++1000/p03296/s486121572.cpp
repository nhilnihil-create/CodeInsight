#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> a(N);
  vector<int> b(N);
  for(int i=0; i<N; i++) cin >> a.at(i);
  for(int i=0; i<N-1; i++){
    if(a.at(i)==a.at(i+1)){
      b.at(i+1)=b.at(i)+1;
      b.at(i)=0;
    }
    else{
      b.at(i+1)=0;
    }
  }
  int ans=0;
  for(int i=0; i<N; i++){
    ans+= (b.at(i)+1)/2;
  }
  cout << ans << endl;
}