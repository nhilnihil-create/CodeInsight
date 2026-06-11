#include <bits/stdc++.h>

using namespace std;

int change(char a,char b,char c){
  if(a==b&&a==c) return 0;
  else {
    if(a==b) return 1;
    if(a==c) return 1;
    if(b==c) return 1;
    else return 2;
  }
}

int main(int argc,char* argv[]){
  int N,count=0;
  string A,B,C;
  cin >> N;
  cin >> A >> B >> C;
  for(int i=0;i<N;i++){
    count+=change(A[i],B[i],C[i]);
  }
  cout << count << endl;

  return 0;
}
