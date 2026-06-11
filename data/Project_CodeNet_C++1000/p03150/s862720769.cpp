#include <bits/stdc++.h>
using namespace std;

int main () {
  string S;
  cin >> S;
  int N = S.size();
  int counta = 0;
  int countb = 0;
  
  if (S.at(0) == 'k'){
    counta++;
    if (counta == 1 && S.at(1) == 'e'){
      counta++;
      if (counta == 2 && S.at(2) == 'y'){
        counta++;
        if (counta == 3 && S.at(3) == 'e'){
          counta++;
          if (counta == 4 && S.at(4) == 'n'){
            counta++;
            if (counta == 5 && S.at(5) == 'c'){
              counta++;
              if (counta == 6 && S.at(6) == 'e'){
                counta++;
              }
            }
          }
        }
      }
    }
  }
  
  
  if (S.at(N-1) == 'e'){
    countb++;
    if (countb == 1 && S.at(N-2) == 'c'){
      countb++;
      if (countb == 2 && S.at(N-3) == 'n'){
        countb++;
        if (countb == 3 && S.at(N-4) == 'e'){
          countb++;
          if (countb == 4 && S.at(N-5) == 'y'){
            countb++;
            if (countb == 5 && S.at(N-6) == 'e'){
              countb++;
              if (countb == 6 && S.at(N-7) == 'k'){
                countb++;
              }
            }
          }
        }
      }
    }
  }
  
  if (counta + countb >= 7){
    cout << "YES" << endl;
  }
  else {
    cout << "NO" << endl;
  }
}
    
    
   
    
    
  
    
      
    
      
   
        
    