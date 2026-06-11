#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); ++i)
#define rep2(i,n) for(int i=1; i<=(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main()
{
  int n,a,b; cin >> n >> a >> b;
  //+e=a +a=b
  if((a+b)%2==0) cout << "Alice" << endl;
  else cout << "Borys" << endl;  
  return 0;
}