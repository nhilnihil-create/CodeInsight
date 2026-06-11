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
  int n,m;
  cin >>n>>m;
  int a[m+1];
  rep(i,m+1){
    a[i] = 0;
  }
  rep(i,n){
    int k;
    cin >> k;
    rep(j,k){
      int tmp;
      cin>>tmp;
      a[tmp]++;
    }
  }
  int count=0;
  for(int i = 1;i<=m;i++){
   if(a[i] == n)
    count++;
//    cout << a[i] << " ";
  }
//  cout << endl;
  cout << count << endl;
}
