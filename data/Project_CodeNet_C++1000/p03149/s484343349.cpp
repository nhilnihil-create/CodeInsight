#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    vector<int> n(4);
    rep(i, 4) {
        cin >> n.at(i);
    } 
   sort(n.begin(), n.end());

   string s="1479";

   rep(i, 4) {
       if (s.at(i)-'0' != n.at(i)) {
           puts("NO");
           return 0;
       }
   }
   puts("YES");
}