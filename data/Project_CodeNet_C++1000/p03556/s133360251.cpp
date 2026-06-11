#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int,string>;

int main() {
int n;
cin >> n;
for(int i = n; i >= 1 ;i--){
  int s = sqrt(i);
  if(s*s == i){
    cout << i << endl;
    return 0;
  }
}
 

 }
