#include <bits/stdc++.h>
using namespace std;

int main() {
   int n; cin >> n;
   vector<string> red(n);
   for(int i = 0; i < n; i++){ cin >> red.at(i); }
   
   int m; cin >> m;
   vector<string> blue(m) ;
   for(int i = 0; i < m; i++){ cin >> blue.at(i); }

   int maxcount = 0;
   for(int i = 0; i < n; i++){
      int count_R = count(red.begin(), red.end(), red.at(i));
      int count_B = count(blue.begin(), blue.end(), red.at(i));
      //cout << red.at(i) << " " << count_R << " " << count_B << endl;
      int R_B = count_R - count_B;
      maxcount = max(maxcount, R_B);
   }
   cout << maxcount << endl;
}
