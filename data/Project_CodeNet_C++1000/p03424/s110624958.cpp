#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  string s="Three";
  
  vector<char>vec(N);
  for(int i=0;i<N;i++){
    cin >> vec.at(i);
    if(vec.at(i)=='Y'){
      s="Four";
      break;
    }
  }
  cout << s <<endl;
  
}
  