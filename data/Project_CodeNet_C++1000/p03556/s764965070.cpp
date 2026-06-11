#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  for(cin>>n;;n--){
    if(sqrt(n)-(int)sqrt(n)>0) continue;
    cout<<n; break;
  }
}