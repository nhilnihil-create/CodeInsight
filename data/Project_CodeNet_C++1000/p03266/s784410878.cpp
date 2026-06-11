#include <bits/stdc++.h>
#include<algorithm>
#define int long long
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

#define INF 1000000000000


signed main()
{
	int a,b;
  cin>>a>>b;
  int k=(a+(b/2))/b;
  int l=a/b;
  if(b%2==1){
    cout<<l*l*l<<endl;
  }
  if (b%2==0){
    cout<<k*k*k+l*l*l<<endl;
  }
}
