#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){
   ll n, m;
   cin >> n >> m;
   if(n == 1 && m == 1)cout << 1;
   else if(n == 1 || m == 1){
    cout << max(m, n) - 2;
   }else cout << (m - 2) * (n - 2);
}
