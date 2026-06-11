#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
 
int main(){
  int a,b,c,d,e,f;
  cin >> a >> b >> c;
  d=max(a,max(b,c));
  e=min(a,min(b,c));
  f=a+b+c-d-e;
  cout << abs(d-f)+abs(f-e) << endl;
}
    
