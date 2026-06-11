#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;

int main(){
  cout << setprecision(10);
  long double n, m, d;
  cin >> n >> m >> d;

  long double ans = 0;

  if(d == 0){
    ans = (m-1) / n;
  } else {
    ans = (m-1) * 2 * (n-d) / n / n;
  }

  cout << ans << endl;
}

