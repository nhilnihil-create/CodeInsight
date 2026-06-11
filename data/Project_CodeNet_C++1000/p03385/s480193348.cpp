#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(){ 
  string s;
  cin >> s;
  if(s == "abc") cout << "Yes" << endl;
  else if(s == "acb") cout << "Yes" << endl;
  else if(s == "bac") cout << "Yes" << endl;
  else if(s == "bca") cout << "Yes" << endl;
  else if(s == "cab") cout << "Yes" << endl;
  else if(s == "cba") cout << "Yes" << endl;
  else cout << "No" << endl;
}
