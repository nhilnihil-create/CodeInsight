#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  string s;
  cin >> s;
  bool f = false;
  if(s == "AKIHABARA") f = true;
  if(s == "KIHABARA") f = true;
  if(s == "AKIHBARA") f = true;
  if(s == "AKIHABRA") f = true;
  if(s == "AKIHABAR") f = true;
  if(s == "KIHBARA") f = true;
  if(s == "KIHABRA") f = true;
  if(s == "KIHABAR") f = true;
  if(s == "AKIHBRA") f = true;
  if(s == "AKIHBAR") f = true;
  if(s == "AKIHABR") f = true;
  if(s == "KIHBRA") f = true;
  if(s == "KIHBAR") f = true;
  if(s == "AKIHBR") f = true;
  if(s == "KIHABR") f = true;
  if(s == "KIHBR") f = true;
  if(f) cout << "YES" << endl;
  else cout << "NO" << endl;
}