#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF = 1e9;
const int maxN = 59;

int n;
ll a[maxN];

void read(){
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> a[i];
}

void solv(){
  ll mn = *min_element(a, a + n);
  ll mx = *max_element(a, a + n);

  cout << n - 1 + n - 1 << '\n';

  if(abs(mn) > abs(mx)){
    ll mnIdx = -1;
    for(int i = 0; i < n; i++){
      if(a[i] == mn){
        mnIdx = i;
        break;
      }
    }

    for(int i = 0; i < n; i++){
      if(mnIdx == i)  continue;
      cout << mnIdx + 1 << " " << i + 1 << '\n';
    }

    for(int i = n - 2; i >= 0; i--)
      cout << i + 1 + 1 << " " << i + 1 << '\n';
  } else {
    ll mxIdx = -1;
    for(int i = 0; i < n; i++){
      if(a[i] == mx){
        mxIdx = i;
        break;
      }
    }

    for(int i = 0; i < n; i++){
      if(mxIdx == i)  continue;
      cout << mxIdx + 1 << " " << i + 1 << '\n';
    }

    for(int i = 1; i < n; i++){
      cout << i - 1 + 1 << " " << i + 1 << '\n';
    }
  }

}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  read();
  solv();

  return 0;
}
