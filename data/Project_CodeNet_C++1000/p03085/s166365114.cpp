#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep2(i, a, b) for(int i = (a); i < (b); i++)
typedef long long ll;

int main() {
   char b;
   cin >> b;

   char ans;

   switch(b) {
    case 'A':
    ans = 'T';
    break;

    case 'T':
    ans = 'A';
    break;

    case 'C':
    ans = 'G';
    break;

    case 'G':
    ans = 'C';
    break;
   }

   cout << ans << endl;
}