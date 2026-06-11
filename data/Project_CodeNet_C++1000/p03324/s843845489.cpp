#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define prtd(var, i) cout << fixed << setprecision(i) << var << endl;
#define ll long long
#define P pair<int, int>
using namespace std;

int main() { 
  int d, n;
  cin >> d >> n;
  if(n == 100) n++;
  if(d == 0){
    cout << n << endl;
  }else if (d == 1){
    cout << 100*n << endl;
  }else{
    cout << 10000*n << endl;
  }

}
