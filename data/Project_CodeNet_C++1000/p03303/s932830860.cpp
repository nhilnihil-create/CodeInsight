#include <bits/stdc++.h>
#define r(i,n) for(int i = 0; i<n; i++)
using namespace std;

int main(){
  int w;
  string s;
  cin >> s>>w;
  r(i,s.length()){
    cout <<s.at(i);
    i+=w-1;
  }
}