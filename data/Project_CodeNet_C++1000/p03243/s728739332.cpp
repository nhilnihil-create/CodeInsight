#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string A;
  cin >> A;
  
  if(A[0]<A[1] ||((A[0]==A[1])&&(A[0]<A[2]))){
    cout << ((atoi(A.c_str())+1)/100+1)*111 << endl;
  }
  else{
    cout << (atoi(A.c_str())/100)*111 << endl;
  }
}