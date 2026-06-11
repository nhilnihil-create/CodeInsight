#include <bits/stdc++.h>
using namespace std;

int main() {
  int N ;
  cin >> N;
  string S;
  bool check = false;
  for(int i = 0; i < N; i++){
  	cin >> S;
    if(S == "Y"){
    	check = true;
        break;
    }
  }
  if(check == false){
  	cout << "Three" << endl;
  }else{
  	cout << "Four" << endl;
  }
}
