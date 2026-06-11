#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a,b,c;
  cin >> a >> b >> c;
  int d = 0;
  int e = 0;
  int f = 0;
  for(int i = 0;i < a;++i){
    int rrr;
    cin >> rrr;
    if(rrr <= b){d++;}
    else if(rrr <= c){e++;}
    else{f++;}
  }
    cout << min(d,min(e,f)) << endl;
  }