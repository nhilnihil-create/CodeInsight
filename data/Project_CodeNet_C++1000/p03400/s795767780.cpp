#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;

int func(int choco, int d){
  int ret=1;
  for(int i = 1; i < d; i++){
	if(i * choco + 1 <= d){
      ret++;
    }
  }
  return ret;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n,d,x;
  cin>>n>>d>>x;
  int a[n];
  rep(i,n) cin >> a[i];
  int sum = 0;
  rep(i,n) sum += func(a[i],d);
  cout << sum + x << endl;
}
