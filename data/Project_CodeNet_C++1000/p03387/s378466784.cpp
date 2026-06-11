#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){

   int A,B,C; cin >> A >> B >> C;
   int maxv = max({A,B,C});
   if(maxv %2 != (A+B+C)%2) maxv++;
   
   int sum = (maxv - A) + (maxv - B) + (maxv - C);
   cout << sum / 2 << endl;
}