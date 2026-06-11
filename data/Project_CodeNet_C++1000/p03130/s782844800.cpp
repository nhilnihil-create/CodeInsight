#include <bits/stdc++.h>

 using namespace std;
 typedef long long ll;

 int main() {
   vector<int> count(4);

   for (int i = 0; i < 6; i++) {
     int tmp;
     cin >> tmp;
     count.at(tmp - 1)++;
   }

   sort(count.begin(), count.end());

   vector<int> cor = {1, 1, 2, 2};

   if (count == cor) cout << "YES" << endl;
   else cout << "NO" << endl;
  }
