#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n,x;
  cin >> n>>x;
  int input, count=0;
  vector<int> a(n);
  rep(i, n) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  rep(i,n) {
	if(x >= a[i]) {
      x-=a[i];
      count++;
    }else{
      cout << count << endl;
      return 0;
    }
  }
  if(x > 0 && count > 0) count--;
  cout << count << endl;
}
