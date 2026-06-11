#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
const double PI = acos(-1);  

int main(){
  string s; cin >> s;

  string ans="YES";
  if(s=="AKIHABARA");
  else if(s=="KIHABARA" || s=="AKIHBARA" || s=="AKIHABRA"|| s=="AKIHABAR");
  else if(s=="KIHBARA" || s=="KIHABRA" || s=="KIHABAR");
  else if(s=="AKIHBRA" || s=="AKIHBAR" || s=="AKIHABR");
  else if(s=="KIHBRA" || s=="KIHBAR" || s=="AKIHBR"|| s=="KIHABR" );
  else if(s=="KIHBR");
  else ans = "NO";
  cout << ans << endl;
}
