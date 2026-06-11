#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)

int main(){
  int N,A,B;
  cin >> N >> A >> B;
  
  if(N == 2) cout << "Borys" << endl;
  else if((B-A)%2 == 0) cout << "Alice" << endl;
  else cout << "Borys" << endl;
}
