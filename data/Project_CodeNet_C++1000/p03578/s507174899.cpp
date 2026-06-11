#include <bits/stdc++.h>
using namespace std;

int main(){
  int Nmade,Ncont; 
  cin >> Nmade;
  unordered_map<int, int> diffs_made;
  int diff;
  for(int i=0; i<Nmade; i++){
    cin >> diff;

    if(!diffs_made.count(diff)){
      diffs_made[diff]= 1;
    }
    else{
      diffs_made.at(diff)++;
    }
  }

  cin >> Ncont;

  bool is_satisfied= true;
  for(int i=0; i<Ncont; i++){
    cin >> diff;

    if(!diffs_made.count(diff) || diffs_made.at(diff)==0){
      is_satisfied= false;
      break;
    }
    else{
      diffs_made.at(diff)--;
    }
  }

  string ans= is_satisfied ? "YES"
                           : "NO";

  cout << ans << endl;
}