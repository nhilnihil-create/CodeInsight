#include <bits/stdc++.h>

 using namespace std;
 typedef long long ll;

 int main() {
   int N, RH;
   string s;
   cin >> N >> s;

   for (int i = 0; i < N; i++) {
     if (s.at(i) == 'R') RH++;
   }
   if (RH > N - RH) cout << "Yes" << endl;
   else cout << "No" << endl;
  }
