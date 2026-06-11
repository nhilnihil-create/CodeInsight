#include <bits/stdc++.h>
using namespace std;
int a, t, d, p;


int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>t>>d>>p;
    a=t+d;
    if (a>=p) {
        cout<<p+d;
    } else {
        cout<<a+d+1;
    }

  
  
   return 0;
}