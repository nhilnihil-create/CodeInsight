#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
ll mod=1e9+7;

int main() {
  string s;
  cin >> s;
  string a="AKIHABARA";
  if(s.size()==5) {
    if(s=="KIHBR") {
      cout << "YES" << endl;
      return 0;
    }
  }
  if(s.size()==6) {
    if(s=="AKIHBR"||s=="KIHABR"||s=="KIHBAR"||s=="KIHBRA") {
      cout << "YES" << endl;
      return 0;
    }
  }
  if(s.size()==7) {
    if(s=="AKIHABR"||s=="AKIHBAR"||s=="AKIHBRA"||s=="KIHABAR"||s=="KIHABRA"||s=="KIHBARA") {
      cout << "YES" << endl;
      return 0;
    }
  }
  if(s.size()==8) {
    if(s=="AKIHABAR"||s=="AKIHABRA"||s=="AKIHBARA"||s=="KIHABARA") {
      cout << "YES" << endl;
      return 0;
    }
  }
  if(s==a) {
    cout << "YES" << endl;
    return 0;
  }
  cout << "NO" << endl;
}