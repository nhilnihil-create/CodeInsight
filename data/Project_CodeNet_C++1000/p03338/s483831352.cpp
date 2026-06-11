#include <bits/stdc++.h>

using namespace std;

int main(){
  int N;
  string S;
  cin >> N;
  cin >> S;
  string X, Y;
  X = Y = "";
  //cout << 122-(int)'a' << endl;

  int bx[26];
  int by[26];
  int ans = 0;

  for(int brd = 0 ; brd < N-1 ; brd++){
    string X, Y;
    X = Y = "";
    for(int i = 0 ; i <= brd ; i++){
      X +=S[i];
      bx[122-(int)S[i]] = 1;
    }
    
    for(int i = brd+1 ; i < N ; i++ ){
      Y +=S[i];
      by[122-(int)S[i]] = 1;
    }
    
    //cout << "ok" << endl;
    
    int ansk = 0;
    for(int i = 0 ; i < 26 ; i++){
      if(bx[i] == 1 && by[i] == 1){
	ansk++;
      }
      bx[i] = by[i] = 0;
    }
    if(ansk > ans){
      ans = ansk;
    }

    
    //cout << brd << endl;
    //cout << "X is " << X << "Y is " << Y << ans <<endl;


      
  }
  cout << ans << endl;
}
