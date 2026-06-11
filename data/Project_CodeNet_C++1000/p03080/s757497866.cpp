#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,r;
  string s;
  cin >> N;
  cin >> s;
  for(int i=0; i<N; i++){
   if(s[i] == 'B'){
     r--;
   }
    else{
      r++;
    }
  }
  if(r>0){
    cout << "Yes" << endl;
    return 0;
  }
  cout << "No" << endl;
}
