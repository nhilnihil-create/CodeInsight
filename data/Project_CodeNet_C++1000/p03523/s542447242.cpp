#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const int MAX = 510000;

int main() {
  string S;
  cin >> S;
  if (S=="AKIHABARA") cout << "YES"<< endl;
  else if (S=="KIHABARA"||S=="AKIHBARA"||S=="AKIHABRA"||S=="AKIHABAR") cout << "YES" << endl;
  else if (S=="KIHBARA"||S=="KIHABRA"||S=="KIHABAR"||S=="AKIHBRA"||S=="AKIHBAR"||S=="AKIHABR") cout << "YES" << endl;
  else if (S=="AKIHBR"||S=="KIHABR"||S=="KIHBAR"||S=="KIHBRA") cout << "YES" << endl;
  else if (S=="KIHBR") cout << "YES" << endl;
  else cout << "NO" << endl;
}