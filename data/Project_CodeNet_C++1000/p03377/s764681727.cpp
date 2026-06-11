#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
using P = pair <int, int>;



int main(){
   int a, b, x;
   cin >> a >> b >>x;
   if(a==x) cout << "YES" <<endl;
   else if(x-a>=0&&b>=(x-a)) cout << "YES" << endl;
   else cout << "NO" << endl;
      }