#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
   int A, B, C, D;
   cin >> A >> B >> C >> D;

   if(A + B < C + D) cout << "Right";
   else if(C + D < A + B) cout << "Left";
   else cout << "Balanced";
   
    return 0;
}
