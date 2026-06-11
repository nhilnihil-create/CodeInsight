#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,a,b;
  cin >> n >> a >> b;
  if(abs(a-b)%2==0) cout << "Alice" << endl;
  else cout << "Borys" << endl;
  return 0;
    

}
