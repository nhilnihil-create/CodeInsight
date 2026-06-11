#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define All(V) v.begin(), v.end()
typedef long long int ll;
typedef pair<int, int> P;
const ll MOD = 1e9+7, INF = 1e9;

int main() 
{
  string s, t; cin >> s >> t;
  if(s > t) cout << ">" << endl;
  else if(s < t)cout << "<" << endl;
  else cout << "=" << endl;
  system("pause");
}