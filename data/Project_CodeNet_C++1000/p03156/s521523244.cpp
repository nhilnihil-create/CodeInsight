#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
typedef long long ll;

int n,a,b,p[110];
string t;

int main() {
  cin >> n >> a >> b;
  rep(i,n)
  cin >> p[i];
  int c=0,d=0,e=0;
  rep(i,n){
    if(p[i]<=a) c++;
    else if(p[i]<=b) d++;
    else e++;
  }
  cout << min({c,d,e}) << endl;
}