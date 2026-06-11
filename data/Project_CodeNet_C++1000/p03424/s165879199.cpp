#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  string s[N];
  bool frag=false;
  for(int i=0;i<N;i++)cin >> s[i];
  for(int i=0;i<N;i++){
    if(s[i]=="Y") frag=true;
  }
  if(frag){
  cout << "Four" << endl;
  }else{
  cout << "Three" << endl;
  }
}