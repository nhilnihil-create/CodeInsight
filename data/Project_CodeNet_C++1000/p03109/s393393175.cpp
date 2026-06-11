#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
   string S;
   cin >> S;

   if(S[5] == '0') {
    if(S[6] == '4' || S[6] == '3' || S[6] == '2' || S[6] == '1') {
        cout << "Heisei";
        return 0;
    }
   }

   cout << "TBD";    
   return 0;
}