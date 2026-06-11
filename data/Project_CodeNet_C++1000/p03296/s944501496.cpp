#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> c(N);
  for(int i = 0; i < N; i++){
    cin >> c.at(i);
  }
  int count = 0;
  for(int i = 0; i < N; i++){
    if(i > 0){
      if(c.at(i-1) == c.at(i)){
        c.at(i) = 0;
        count++;
      }
    }
  }
  cout << count << endl;

}