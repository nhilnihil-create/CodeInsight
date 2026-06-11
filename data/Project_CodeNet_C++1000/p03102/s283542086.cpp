#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 1000000000; // 10^9

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n,m,c,res;
  cin>>n>>m>>c;

  int arr[m];

  for(int i=0; i<m; i++) {
    cin>>arr[i]; 
  }

  res = 0;
  while(n--) {
    ll ans = 0;
    int a;

    for(int i=0; i<m; i++) {
      cin>>a;
      ans += a*arr[i]; 
    }
    ans+=c;
    if(ans>0) {
      res++;
    }
  }

  cout << res << '\n';

  return 0;
}

