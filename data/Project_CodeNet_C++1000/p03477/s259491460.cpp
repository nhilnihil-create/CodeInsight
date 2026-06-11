#include<bits/stdc++.h>
using namespace std;
 
#define ll long long

signed main(){
  int a,b,c,d; cin >> a >> b >> c >> d;
  if((a+b)>(c+d)) {cout << "Left";}
  else if((a+b)==(c+d)) {cout << "Balanced";}
  else if((a+b)<(c+d)) {cout << "Right";}
}