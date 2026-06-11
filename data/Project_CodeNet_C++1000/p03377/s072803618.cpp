#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
 
int main(){
  int A, B, X;
  cin >> A >> B >> X;
  for(int i=0;i<=B;i++){
    if(A==X){
      break;
    }
  A++;
  }
  if(A==X){
  cout << "YES" << endl;
  }
  else{
  cout << "NO" << endl;
  }
}