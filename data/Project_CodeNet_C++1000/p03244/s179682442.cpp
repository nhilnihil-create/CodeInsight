#include <bits/stdc++.h>
using namespace std;
 
const int maxn = 1e5 + 5;
int aodd[maxn];
int aeven[maxn];
 
int main(){
  int n; cin >> n;
  int x;
  memset(aodd,0,sizeof(aodd));
  memset(aeven,0,sizeof(aeven));
  int a1 = 0, b1 = 0, a2 = 0, b2 = 0,c1 = 0, c2 = 0;
  //int z = 0, y = 0;
  for(int i = 0; i < n; ++i){
     cin >> x;
     if(i%2){aeven[x]++; 
     
         if(aeven[x] > a1)c1 = x;
         if(c1 != x)b1 = max(b1,aeven[x]);
         a1 = max(a1,aeven[x]);
     }
     else{ 
         aodd[x]++;
         if(aodd[x] > a2)c2 = x;
         if(c2 != x)b2 = max(b2,aodd[x]);
         a2 = max(a2,aodd[x]);
     }
  }
  //cout << a1 << ' ' << a2 << '\n';
  if(c1 != c2) cout << n - a1 - a2 << '\n';
  else cout << min(n - (a1 + b2),n - (b1 + a2)) << '\n';
}