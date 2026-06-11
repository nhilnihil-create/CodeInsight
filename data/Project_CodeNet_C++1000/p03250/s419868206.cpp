#include <bits/stdc++.h>
#include <algorithm>

 using namespace std;
 int main(){
 int A,B,C;
   cin >>A>>B>>C;
   int ans = max<int>({10*A+B+C,10*B+A+C,10*C+A+B});
   cout << ans << endl;
 }