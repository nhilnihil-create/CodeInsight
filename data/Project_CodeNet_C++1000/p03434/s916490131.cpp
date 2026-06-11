#include <bits/stdc++.h>
using namespace std;

int main() {

  int n;
  cin >> n ;
  vector<int> C(n); 

  for (int i=0;i<n;i++){
    cin >> C.at(i) ;
  }

  sort(C.begin(),C.end());
  reverse(C.begin(),C.end());

  int A=0,B=0;

  for (int j=0;j<n;j=j+2){
    A=A+C.at(j);
    
    if (j+1<n){
      B=B+C.at(j+1);
    }
   
  }

  cout << A-B << endl;
  
}
