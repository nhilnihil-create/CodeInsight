#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
const int inf = 1001001001;


int main(){
  int n;
  cin >> n;

  int x = n;
  int f = 0;
  while(x>0){
    f += x%10;
    x /= 10;
  }

  cout << (n%f==0 ? "Yes":"No") << endl;
  
}
