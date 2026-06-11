#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vecll vector<long long>
#define vec2ll vector<vector<long long>>
#define vecpairll vector<pair<long long,long long>>
#define forll(s,a,b) for(long long s = a;s < b;s++)
#define forllde(s,a) for(long long s = a;s > 0;s--)


int main()
{
  string s;
  cin >> s;
  vecll a(26, 0);
  if(s == "zyxwvutsrqponmlkjihgfedcba"){
	cout << -1 << endl;
	return 0;
  }
  if(s.size() < 26){
	forll(i, 0, s.size())
	  a[s[i] - 'a']++;
	forll(i, 0, 26){
	  if (a[i] == 0){
		s += (i + 'a');
		cout << s << endl;
		return 0;
	  }
	}
  }
  string t = s;
  next_permutation(s.begin(), s.end());
  forll(i, 0, 26){
	cout << s[i];
	if (s[i] != t[i]){
	  cout << endl;
	  return 0;
	}
  }
  cout << endl;
}
