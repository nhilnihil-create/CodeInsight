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
  ll a,b,c,k;
  cin>>a>>b>>c>>k;
  if(k%2==0){
  	cout << a-b <<endl;
  }
  else{
    cout << b-a << endl;
  }
}