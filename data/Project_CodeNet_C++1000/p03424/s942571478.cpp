#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  string s;
  
  bool pink = false;
  bool white = false;
  bool green = false;
  bool yellow = false;
  cin >> N;
  
  for(int i=0;i<N;i++){
    cin >> s;
    if(s == "P") pink = true;
    if(s == "W") white = true;
    if(s == "G") green = true;
    if(s == "Y") yellow = true;
  }
  
  if(pink && white && green && yellow){
    cout << "Four" << endl;
  }else if(pink && white && green){
    cout << "Three" << endl;
  }
  
}