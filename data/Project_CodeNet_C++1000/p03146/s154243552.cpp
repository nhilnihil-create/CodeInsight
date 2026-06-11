#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ll s;
  vector<bool> a(1000000,false);
  cin >> s;
  ll count = 1;
  a[s] = true;
  while(true){
    if(s%2==0) s=s/2;
    else s=3*s+1;
    count++;
    if(a[s] == true) break;
    a[s] = true;
  }
  cout << count << endl;
}
