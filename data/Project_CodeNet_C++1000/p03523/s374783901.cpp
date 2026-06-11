#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin >> S;
  vector<string> T={"AKIHABARA","AKIHABAR","AKIHABRA","KIHABARA","AKIHABR","AKIHBAR","AKIHBRA",
                    "KIHABAR","KIHABRA","KIHBARA","AKIHBR","KIHABR","KIHBAR","KIHBRA","KIHBR"};
  bool a=false;
  for(int i=0;i<15;i++){
    if(S==T.at(i)){
      a=true;
      break;
    }
  }
  if(a){
    cout << "YES" << endl;
  }
  else{
    cout << "NO" << endl;
  }
}
      
