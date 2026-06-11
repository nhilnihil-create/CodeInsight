#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int inf = 1001001001;

int main(){
  int r;
  cin >> r;
  
  if(r < 1200) cout << "ABC" << endl;
  if(1200 <= r && r < 2800) cout << "ARC" << endl;
  if(2800 <= r) cout << "AGC" << endl;
  
}