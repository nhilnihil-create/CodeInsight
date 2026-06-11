#include <bits/stdc++.h>
using namespace std;

int main() {
 int N;
  cin >> N;
  // breakがなければこのループは i == 4 まで繰り返す
  for (int i = 0; i <= N; i++) {
    string s;
    cin >> s;

    if (s == "Y") {
      cout << "Four" << endl;
      break; // s == Y の時点でループから抜ける
    }

   if (i == N){
     cout << "Three" << endl;
   }
  }

}
