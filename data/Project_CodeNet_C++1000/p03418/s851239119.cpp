//#include<bits/stdc++.h>
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<numeric>
#include<vector>
#include<set>
#include<map>
#include<unordered_map>
#include<stack>
#include<queue>
#include<list>
using namespace std;

int main(){
  int n,k,p,q;
  cin >> n >> k;
  long long ans = 0;
  for(int b=k+1;b<=n;b++){
    p = n/b;
    q = n%b;
    ans += max(q-k+1,0);
    ans += p*(b-k);
  }
  if(k == 0) ans -= n;
  cout << ans << endl;

  return 0;
}
