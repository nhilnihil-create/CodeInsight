#include<bits/stdc++.h>
using namespace std;
int main(){
  string S;
  cin >> S;
  if(S == "AKIHBR" || S == "AKIHABR" || S == "AKIHABAR" || S == "AKIHABARA" || S == "AKIHABRA" || S == "AKIHBAR" || S == "AKIHBARA" || S == "AKIHBRA"){
    cout << "YES" << endl;
  }
  else if(S == "KIHBR" || S == "KIHABR" || S == "KIHABAR" || S == "AKIHABARA" || S == "KIHABRA" || S == "KIHBAR" || S == "KIHBARA" || S == "KIHBRA"){
    cout << "YES" << endl;
  }
  else{
    cout << "NO" << endl;
  }
}