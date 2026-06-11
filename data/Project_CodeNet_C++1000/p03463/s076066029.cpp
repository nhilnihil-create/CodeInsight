#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
#define REP(i,a,n) for(int (i)=(a); (i)<(int)(n); (i)++)
#define rep(i,n) REP(i,0,n)
#define vec vector 


int main(){
  int N, A, B;
  cin >> N >> A >> B;
  
  if((A-B)%2==0){
    cout << "Alice";
  }else{
    cout << "Borys";
  }
}