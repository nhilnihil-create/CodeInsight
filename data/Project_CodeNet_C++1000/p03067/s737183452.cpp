#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
int main(){
  int A,B,C;
  cin>>A>>B>>C;
  if (A < B){
    if (A < C && C < B){
      cout << "Yes" << endl;
    }else{
      cout << "No" << endl;
    }
  }else{
    if (B<C && C < A) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
  return 0;
}
