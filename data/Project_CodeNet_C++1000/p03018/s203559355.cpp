#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin >> S;
  const int64_t N= int64_t(S.size());

  int64_t ans= 0;
  int64_t cntA= 0;
  for(int i=0; i<N;){
    char c= S.at(i);
    if(c=='A'){
      cntA++;
      i++;
    }
    else if(c=='C'){
      cntA= 0;
      i++;
    }
    else{ // c=='B'
      i++;
      if(i==N){ break; }
      else{
        if(S.at(i)=='B'){
          cntA= 0;
          i++;
        }
        else if(S.at(i)=='A'){
          cntA= 1;
          i++;
        }
        else{ // S.at(i)=='C'
          ans+= cntA;
          i++;
        }
      }
    }
  }


  cout << ans << endl;
}