#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector <int> a;
  bool flag_2 = true;
  for(int i = 0; i < N; i++){
    int n_a;
    cin >> n_a;
    a.push_back(n_a);
  }

  for(int c: a){
    if(c%2 != 0){
      cout << "0" << endl;
      flag_2 = false;
      break;
    }else{
      continue;
    }
  }

  int least = 0;

  if(flag_2){
    for(int i = 1;; i++){
      for(int c: a){
        int n_2 = pow(2, i);
        if(c%n_2 != 0){
          cout << i - 1 << endl;
          return 0;
        }else{
          continue;
        }
      }
    }
  }
}
