#include <bits/stdc++.h>
using namespace std;
#include<cstdlib>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
typedef long long ll;

int main(){
  int a,b;
  cin >> a >> b;

  if(a>=13)cout << b;
  else if(a<=5)cout << 0;
  else cout << b/2;
}