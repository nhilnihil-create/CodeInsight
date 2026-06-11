#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <cmath>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <unordered_map>
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;

int main()
{
	int n; ll x;
  cin>>n>>x;
  ll s[200001];
  s[0]=0;
  for(int i=1; i<=n; i++){
    ll xi; cin>>xi;
    s[i]=s[i-1]+xi;
  }
  ll ans=1e18;
  for(int d=1; d<=n; d++){
    ll ans1=x*(ll)(n+d)+5*(s[n]-s[n-d]);
    for(int i=1; n-i*d>0; i++){
      ans1+=(3+2*(ll)i)*(s[n-i*d]-s[max(n-(i+1)*d, 0)]);
      if(ans1>1e18) break;
    }
    ans=min(ans, ans1);
  }
  cout<<ans<<endl;
	return 0;
}