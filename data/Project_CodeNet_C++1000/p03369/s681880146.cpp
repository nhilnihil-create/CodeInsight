#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
 
int main(){
  int total=700;
  string S;
  cin >> S;
  rep(i,3){
    if(S.at(i)=='o'){
      total+=100;
    }
  }
  cout << total << endl;
}
      
      
