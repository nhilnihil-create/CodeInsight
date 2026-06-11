#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define eb emplace_back

typedef long long ll;
typedef unsigned long long ull;

// 46786 - 106

void oneCase() {
   int a, b, c;
   cin>> a >> b >> c;
   if (a == b) {
       cout << c;
   } else if (c == a) {
       cout << b;
   } else {
       cout << a;
   }
   cout << "\n";

}


int main() {
    int t = 1;
//    cin >> t;
    while (t--) {
       oneCase();
    }

    return 0;
}
