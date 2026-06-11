#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <cmath>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <complex>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <cassert>
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;

int main()
{
	int h, w, n; cin>>h>>w>>n;
  int sr, sc; cin>>sr>>sc;
  int a=1, b=h, c=1, d=w;
  string s, t;
  cin>>s>>t;
  for(int i=n-1; i>=0; i--){
    if(t[i]=='L') d=min(d+1, w);
    else if(t[i]=='R') c=max(c-1, 1);
    else if(t[i]=='U') b=min(b+1, h);
    else a=max(a-1, 1);
    if(s[i]=='L') c=min(c+1, w+1);
    else if(s[i]=='R') d=max(d-1, 0);
    else if(s[i]=='U') a=min(a+1, h+1);
    else b=max(b-1, 0);
    if(a>b || c>d){
      cout<<"NO"<<endl;
      return 0;
    }
  }
  if(a<=sr && sr<=b && c<=sc && sc<=d) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
	return 0;
}