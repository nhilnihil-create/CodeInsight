#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
ll mod=1e9+7;

int main() {
  string s;
  cin >> s;
  if(s=="KIHBR"||s=="AKIHBR"||s=="KIHABR"||s=="KIHBAR"||s=="KIHBRA"||s=="AKIHABR"||s=="AKIHBAR"||s=="AKIHBRA"||s=="KIHABAR"||s=="KIHABRA"||s=="KIHBARA"||s=="AKIHABAR"||s=="AKIHABRA"||s=="AKIHBARA"||s=="KIHABARA"||s=="AKIHABARA") cout << "YES" << endl;
  else cout << "NO" << endl;
}