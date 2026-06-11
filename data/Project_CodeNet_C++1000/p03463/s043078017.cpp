#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define all(vec) vec.begin(),vec.end()
using ll = long long;

int main() {
  int N, A, B; cin >> N >> A >> B;
   if ((B-A)%2 == 1) cout << "Borys" << endl;
   else cout << "Alice" << endl;
    
  return 0;
  
}