#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
   int N;
   cin >> N;
   vector<string> v(N);
   for(int i=0; i<N; i++) cin >> v[i];

   int M;
   cin >> M;
   vector<string> w(M);
   for(int i=0; i<M; i++) cin >> w[i];

   int div = 0;

   for(string s : v) {
      int v_n = count(v.begin(), v.end(), s);
      int w_n = count(w.begin(), w.end(), s);
      div = max(div, v_n - w_n);

   }
   cout << div << endl;
}