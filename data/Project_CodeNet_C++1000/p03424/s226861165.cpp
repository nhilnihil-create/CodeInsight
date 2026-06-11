#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
  	string S;
    int count = 0;
    cin >> N;
    for(int i = 0; i < N; i++){
      cin >> S;
      if(S == "Y"){
        count++;        
      } else {
        continue;
      }
    }
  
    if(count >= 1){
      cout << "Four" << endl;
    } else {
      cout << "Three" << endl;
    }
 
}