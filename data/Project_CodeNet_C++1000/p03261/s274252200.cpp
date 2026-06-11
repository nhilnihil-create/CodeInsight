#include<bits/stdc++.h>
using namespace std;
int main(){
  int N ;
  cin >> N;
  vector<string> w(N);
  for(int i= 0; i<N; i++){
    cin >> w.at(i);
  }
  for(int i = 0; i<N-1; i++){
    for(int j= i+1; j<N; j++){
      if(w.at(i) == w.at(j)){
        cout << "No" << endl;
        return 0;
      }
    }
  }
  for(int i = 0; i< N-1; i++){
    string w_1, w_2;
    w_1 = w.at(i);
    w_2 = w.at(i+1);
    if(w_1.at(w_1.size()-1) != w_2.at(0)){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  
}
