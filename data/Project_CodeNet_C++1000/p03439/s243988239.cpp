#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  int begin = 0;
  int end = 2*N-2;
  int query;
  bool flag = true;
  
  string S;
  cout << 0 << endl;
  fflush(stdout);
  cin >> S;
  if(S == "Vacant"){
    flag = false;
  }
  
  while(flag){
    string T;
    query = (begin + end)/2;
    if(query %2 != 0){
      query++;
    }
    cout << query << endl;
    cin >> T;
    fflush(stdout);
    if(T == "Vacant"){
      flag = false;
      break;
    }
    else if(S == T){
      begin = query;
    }
    else if(S != T){
      end = query;
    }
    if(end - begin == 2){
      cout << begin + 1 << endl;
      fflush(stdout);
      flag = false;
    }
  }
}  