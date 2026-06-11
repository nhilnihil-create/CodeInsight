#include <bits/stdc++.h>
using namespace std;

int main() {
   int N, C_money;
   cin >> N >> C_money;
   vector<int> v(N);

   for(int i=0; i<N; i++) {
       cin >> v[i];
       C_money -= v[i];
   }

   sort(v.begin(), v.end());

   N += C_money / v[0];
    cout << N << endl;
}
