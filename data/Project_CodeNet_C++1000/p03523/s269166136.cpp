#include <bits/stdc++.h>

 using namespace std;
 typedef long long ll;
 #define rep(i, n) for(int i = 0; i < (int)(n); i++)

 int main() {
   string S, ans = "YES";
   cin >> S;

   if (S.length() > 9) ans = "NO";

   else if (S.length() == 9) {
     if (S != "AKIHABARA") ans = "NO";
   }

   else if (S.length() == 8) {
     if (S != "KIHABARA" && S != "AKIHBARA" && S != "AKIHABRA" && S != "AKIHABAR") ans = "NO";
   }

   else if (S.length() == 7) {
     if (S != "KIHBARA" && S != "KIHABRA" && S != "KIHABAR" && S != "AKIHBRA" && S != "AKIHBAR" && S != "AKIHABR") ans = "NO";
   }

   else if (S.length() == 6) {
     if (S != "AKIHBR" && S != "KIHABR" && S != "KIHBAR" && S != "KIHBRA") ans = "NO";
   }

   else if (S.length() == 5) {
     if (S != "KIHBR") ans = "NO";
   }
   else ans = "NO";

   cout << ans << endl;
 }
