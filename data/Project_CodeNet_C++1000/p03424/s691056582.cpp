#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int N,P=0,W=0,G=0,Y=0;
  cin >> N;
  string s;
  int a = 0;

  for(int i = 0; i < N; i++){
    cin >> s;
    if(s == "P"){
      P = 1;
    }else if(s == "W"){
      W = 1;
    }else if(s == "G"){
      G = 1;
    }else if(s == "Y"){
      Y = 1;
    }
  }
  a = P + W + G + Y;
  if(a == 3){
    cout << "Three" << endl;
  }else{
    cout << "Four" << endl;
  }

}


