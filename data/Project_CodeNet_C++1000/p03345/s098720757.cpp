#include<bits/stdc++.h>
using namespace std;
#define majn main
int majn(){
  long long a,b,c,k;
  cin >> a >> b >> c >> k;
  if(k%2==0)cout << a-b;
  else cout << b-a;
}
