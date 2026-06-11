#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  string A,B;
  cin>>A>>B;
  if(A[0]==B[2]&&A[1]==B[1]&&A[2]==B[0]){
    cout<<"YES"<<endl;
  }
  else{
    cout<<"NO"<<endl;
  }
}