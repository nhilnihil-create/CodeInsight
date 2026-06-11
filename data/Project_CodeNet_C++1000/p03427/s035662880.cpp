#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <algorithm>
#include <utility>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 int ctoi(char c) {
 	switch (c) {
		case '0': return 0;
		case '1': return 1;
		case '2': return 2;
		case '3': return 3;
		case '4': return 4;
		case '5': return 5;
		case '6': return 6;
		case '7': return 7;
		case '8': return 8;
		case '9': return 9;
		default: return 0;
	}
}
int main(){
  string N; cin >> N;
  int sum = 0;
  bool flag = true;
  if(N.size() == 1){
    cout << ctoi(N[0]) << endl;;
  }
  else{
    for(int i=1; i < N.size();i++){
      if(N[i] != '9'){
        flag = false;
      }
    }
    if(flag){
      rep(j,N.size()){
        sum += ctoi(N[j]);
    }
    }
    else{
      sum = (N.size()-1)*9;
      sum += ctoi(N[0])-1;
  }
  cout << sum << endl;
  
  }
}