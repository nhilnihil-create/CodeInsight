#include<bits/stdc++.h>
using namespace std;
int main(){
    int A,B,C,D=1;
  cin >> A >>B >> C;
  if(A==B){
    if(A==C){
      cout << "Yes" << endl;
      D=0;
    }
  }
  if(D)cout << "No" << endl;
}
