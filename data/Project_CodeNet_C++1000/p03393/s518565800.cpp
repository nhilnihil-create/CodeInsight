#include<bits/stdc++.h>
#define REP(i, n) for(ll i = 0; i < (ll)n; i++)
#define REPvec(itr, mp) for(auto itr = mp.begin();itr != mp.end(); itr ++)
#define all(x) x.begin(), x.end()
#define MOD 1000000007//1e9+7
using namespace std;
typedef long long unsigned int ll;
typedef vector<int >    vecint;
typedef vector<double >    vecd;
typedef vector<vector<int> >  vec2int;
typedef vector<vector<double> >  vec2d;
typedef vector<ll >     vecll;
typedef vector<string > vecstr;
typedef vector<bool > vecbool;
typedef vector<vector< bool > > vec2bool;
typedef vector<bool > vecbool;
////////////////////////////////////////////////
int main()
{
  string s; cin >> s;
  set<char> g;
  REP(i,s.size()){
    g.insert(s[i]);
  }
  if(s.size() != 26){
    for(char c = 'a'; c < 'z'; c ++ ){
      if(g.find(c) == g.end()){
	s = s + c;
	cout << s << endl;
	return 0;
      }
    }
  }else{
    int ind = 0;
    for(int i = 25; i >= 1; i--){
      if(s[i - 1] < s[i]){
	ind = i;
	break;
      }
    }
    ///// last one
    if(ind == 0){
      cout << -1 << endl;
      return 0;
    }
    ///// last one
    char key;
    key = s[ind - 1];
    // cout << key << " " << ind <<  endl;
    char key2 = 'z';
    for(int i = ind; i <= 25; i ++){
      // cout << s[i] << " " << (key > s[i]) << endl;
      if(key < s[i]){
	key2 = min(key2, s[i]);
      }
    }
    if(ind == 1){
      cout << key2 << endl;
    }else{
      cout << s.substr(0,ind-1) << key2<< endl;
    }
  }
} 
