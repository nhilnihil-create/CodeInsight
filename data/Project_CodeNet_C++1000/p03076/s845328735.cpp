#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
int INF = 100100101;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  vector<int> a(5);
  int mini = INF;
  int sum = 0;
  int itr;
  rep(i,5) {
    cin >> a[i];
    if(a[i]%10 != 0 && a[i]%10 < mini){
      mini = a[i]%10;
      itr = i;
    }
  }
  rep(i,5){
    if(i != itr){
      sum+=ceil(double(a[i]/10.0))*10;
    }
    else{
      sum+=a[i];
    }
  }
  cout << sum << endl;
}