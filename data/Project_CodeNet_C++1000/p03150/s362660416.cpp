#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
  fastIO;
  string s;
  cin >> s;
  int y;
  for(int i = 0 ; i <= 7 ; i ++ ){
    string a = s.substr(0,i);
    y = 7 - i;
    string b = s.substr((int)s.size() - y, y);
    a += b;
    if(a == "keyence"){
      cout << "YES\n";
      return 0;
    }
  }
  cout << "NO\n";
  return 0;
}
