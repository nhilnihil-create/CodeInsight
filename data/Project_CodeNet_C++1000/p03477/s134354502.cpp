#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
#define rep(i,n) for(int i=0; i<n; i++)
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end()) //sortしてから使う
#define INF 2147483647
#define LLINF 9223372036854775807LL

int main(){
  int a,b,c,d; cin>>a>>b>>c>>d;
  if (a+b > c+d) cout << "Left" << endl;
  else if (a+b == c+d) cout << "Balanced" << endl;
  else cout << "Right" << endl;
}