#include<bits/stdc++.h>

#define ll long long
const int inf = 1e9+7;
const ll INF = 1e18+7;

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  if((n&1) == 0)
    cout<<n<<"\n";
  else
    cout<<2*n<<"\n";
}
