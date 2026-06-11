#include<bits/stdc++.h>
using namespace std;

int main() {
  int N,E;
  cin >> N;
  E=0;
  string A="a";
  string B="b";
  string C="c";
  for(int i=0;i<N;i++) {
    string x;
    cin >> x;
    if(A=="a"||A==x) {
      if(A=="a") {
        E++;
      }
      A=x;
    } else {
      if(B=="b"||B==x) {
        if(B=="b") {
          E++;
        }
        B=x;
      } else {
        if(C=="c"||C==x) {
          if(C=="c") {
            E++;
          }
          C=x;
        } else {
          E++;
          break;
        }
      }
    }
  }
  if(E==3) {
    cout << "Three" << endl;
  } else {
    if(E==4) {
      cout << "Four" << endl;
    }
  }
}