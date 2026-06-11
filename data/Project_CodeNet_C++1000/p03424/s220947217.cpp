#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  int answer = 0;

  for(int i = 0; i < N; i++){
    char S;
    cin >> S;
    
    if(S == 'Y'){
      answer++;
    }
    else{
      continue;
    }
  }

  if(answer > 0){
    cout << "Four" <<endl;
  }
   else{
    cout << "Three" <<endl;
  }
}