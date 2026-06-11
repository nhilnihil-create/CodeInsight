#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int,string>;

int main() {
int n,k;
cin >> n >> k;
int s = 1;
rep(i,n){
  if(s*2 < s+k) s *= 2;
  else s += k;
}
cout << s << endl;

 }
