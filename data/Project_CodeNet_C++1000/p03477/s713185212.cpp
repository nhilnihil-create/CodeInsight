#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
#define REP(i,a,n) for(int (i)=(a); (i)<(int)(n); (i)++)
#define rep(i,n) REP(i,0,n)
#define vec vector 


int main(){
  int A, B, C, D;
  cin >> A >> B >> C >> D;
  
  if(A+B > C+D){
    cout << "Left";
  }else{
    if(A+B < C+D){
      cout << "Right";
    }else{
      cout << "Balanced";
    }
  }
  
}