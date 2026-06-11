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
  int x;
  cin>>x;
  vector<bool> a(x+1);
  a[1] = 1;
  for(int i = 2; i <= x; i++){
   	int v = i*i;
    while(v <= x) {
      a[v] = true;
      v*=i;
    }
  }
  for(int i = x; i >0; i--){
    if(a[i]){
      cout << i << endl;
      return 0;
    }
  }
  return 0;
}