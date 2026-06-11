#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <iomanip>
#include <stdlib.h>
#include <queue>

using namespace std;

const int nmax = 1e9 + 7;
typedef long long ll;

int main(){

  int N; cin >> N;

  vector <int> record(N);  

  int now = 0;
  int left = 0, right = N - 1;
  for (int i = 0; i < 20; i++){
    if (i == 0){
      now = 0;
    }else if(i == 1){
      now = N - 1;
    }else{
      now = (left + right) / 2;
    }

    cout << now << endl;
    
    string S; cin >> S;

    if (S == "Vacant"){
      break;
    }else if(S == "Male"){
      record[now] = 1;
    }else{
      record[now] = 2;
    }

    if (i >= 2){
      if (record[left] == record[now] && (now - left) % 2 == 0){
        left = now;
      }else if(record[left] != record[now] && (now - left) % 2 != 0){
        left = now;
      }else{
        right = now;
      }
    }
  }
  
  
  return 0;
}
