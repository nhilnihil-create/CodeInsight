#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  int dan = 0;
  bool hasnext;
  int base = 0;
  int nextbase = 0;
  int nextat = 0;
  
  cin >> N;
  vector<int> mochi(N);
  vector<bool> picked(N);
  
  for(int i = 0; i < N; i++){
    cin >> mochi.at(i);
    if(base < mochi.at(i))
      base = mochi.at(i);
  }
  while(dan < N){
    hasnext = false;
    for(int i = 0; i < N; i++){
    	if(!picked.at(i) && base > mochi.at(i) && nextbase < mochi.at(i)){
          hasnext = true;
    	  nextbase = mochi.at(i);
     	  nextat = i;
   		}
    }
    if(hasnext){
	    base = mochi.at(nextat);
    	picked.at(nextat) = true;
      nextbase = 0;
    	dan++;
    }
    else break;
  }
  
  cout << dan + 1 << endl;
}