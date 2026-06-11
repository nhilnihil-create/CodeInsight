#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int main() {
   int N;
   cin >> N;
   vector<string> V(N);
   rep(i,N) {
       cin >> V[i];
   }

   int count = 0;
   rep(j,N) {
       rep(k,j) {
           if (V[k] == V[j]) {
               count++;
           }
       }
       if (j != 0) {
           if (V[j][0] != V[j - 1][V[j - 1].size() - 1]) {
               count++;
           }
       }
   }
   if (count == 0) {
       cout << "Yes" << endl;
   }
   else {
       cout << "No" << endl;
   }

}

