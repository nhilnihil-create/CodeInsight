 #include <bits/stdc++.h>
using namespace std;

int main() {
int a, b, c, k;
  cin >> a >> b >> c >> k;
  int d = max({a, b, c});
  int e =d;
 for(int i= 0;i<k;++i){
   d *=2;
 }
  
  cout <<d+a+b+c-e  << endl;
}