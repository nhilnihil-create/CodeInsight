#include <bits/stdc++.h>
using namespace std;

int main() {
   string N;
   int ans = 0;
   cin >> N;
   for(int i=1; i<N.size(); i++){
     if(N[i-1] == N[i] && N[i-1] == '1'){
       N[i] = '0';
       ans++;
     }
     else if(N[i-1] == N[i] && N[i-1] == '0'){
       N[i] = '1';
       ans++;
     }
  }
  cout << ans << endl;
}
