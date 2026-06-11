#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A;
  cin >> N >> A;
  string d = "No";

  for(int i=0; i<(N/500+1); i++){
    for(int j=0; j<=A; j++){
      if(500*i+j==N){
        d = "Yes";
        break;
      }

    }
    
  }


  cout << d << endl;


}