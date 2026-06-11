#include <bits/stdc++.h>
using namespace std;

int main(){
  string colorNum = "Three";
  int N = 0;
  cin >> N;
  
  vector<char> S(N);
  for(int i = 0; i < N; i++){
    cin >> S.at(i);
  }
  
  for(int i = 0; i < N; i++){
    switch(S.at(i)){
      case 'P' : continue;
      case 'W' : continue;
      case 'G' : continue;
      case 'Y' : colorNum = "Four"; break;
    }
  }
    cout << colorNum << endl; 
}