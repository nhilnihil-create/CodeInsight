#include <bits/stdc++.h>
using namespace std;

int main(){
   int n;
   cin >> n;
   int l[n];
   int d=0;
   int m=0;
   for(int i=0; i<n; i++){
       cin >> l[i];
       m += l[i];
       d = max(d,l[i]);
   }
   if(m-d>d) cout << "Yes" << endl;
   else cout << "No" << endl;
}