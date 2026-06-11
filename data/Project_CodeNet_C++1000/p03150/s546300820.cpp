#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vecll vector<long long>
#define vec2ll vector<vector<long long>>
#define vecbool vector<bool>
#define vecpairll vector<pair<long long,long long>>
#define forll(s,a,b) for(long long s = a;s < b;s++)
#define forllde(s,a) for(long long s = a;s > 0;s--)


int main()
{
  string s;
  string t = "keyence";
  cin >> s;
  forll(i, 0, s.size() + 1){
	if (s.substr(0, i) == t.substr(0, i) && s.substr(s.size()-t.size()+i) == t.substr(i)){
	  cout << "YES" << endl;
	  return 0;
	}
  }
  cout << "NO" << endl;
}
