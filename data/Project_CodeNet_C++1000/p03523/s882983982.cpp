#include <bits/stdc++.h>
using namespace std;


/*
string t = "AKIHABARA";


int main()
{
  string s;cin >> s;
  int j = 0;
  for (int i = 0; i < t.length(); i++) 
  {
    if (s[j] == t[i])
    {
      j++;
      continue;
    }
    else if (t[i] == 'A')
    {
      continue;
    }
    else
    {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
    
}
*/

vector<string> t = {"AKIHABARA",
"KIHABARA",
"AKIHBARA",
"AKIHABRA",
"AKIHABAR",
"KIHBARA",
"AKIHBRA",
"KIHABAR",
"KIHBRA",
"AKIHBR",
"KIHABR",
"KIHBAR",
"KIHBR",
"AKIHABR"};

int main()
{
  string s; cin >> s;
  for (auto && a : t) 
  {
    if (a == s)
    {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
}