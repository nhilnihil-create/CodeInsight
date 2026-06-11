#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
   string S;
   cin >> S;
   int a, b, c;
   a = 0;
   b = 0;
   c = 0;
   for(int i = 0; i < S.size(); i++) {
       if(S[i] == 'a') a++;
       if(S[i] == 'b') b++;
       if(S[i] == 'c') c++;
   }

   if(a == 1 && b == 1 && c == 1) cout << "Yes";
   else cout << "No";

    return 0;
}
