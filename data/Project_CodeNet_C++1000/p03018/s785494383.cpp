#include<bits/stdc++.h>
#define REP(i, n) for(ll i = 0; i < (ll)n; i++)
#define REPvec(itr, mp) for(auto itr = mp.begin();itr != mp.end(); itr ++)
#define all(x) x.begin(), x.end()
#define MOD 1000000007//1e9+7
using namespace std;
typedef long long ll;
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
  string s;cin >>s;
  int n = s.size();
  vecstr v;
  string tmp = "";
  REP(i,n){
    if(i < n - 1 && s.substr(i,2) == "BC"){
      tmp += "D";
      i++;
      if(i == n - 1){
	v.push_back(tmp);
      }
    }else if(s[i] == 'B'||s[i] == 'C'){
      if(tmp.size() > 0){
	v.push_back(tmp);
      }
      tmp = "";
    }else{
      tmp += "A";
      if(i == n - 1){
	v.push_back(tmp);
      }
    }// else{
    //   cout << "ERROR"  << s[i] << endl;
    // }
    // cout << i << " " <<s[i] << " " <<tmp << endl;
  }
  // REPvec(itr, v){
  //   cout << *itr << endl;
  // }
  ll ans = 0;
  REPvec(itr, v){
    string ss = *itr;
    int m = ss.size();
    vecint na(m,0);
    if(ss[0] == 'A'){
      na[0] = 1;
    }
    REP(i,m - 1){
      if(ss[i + 1] == 'A'){
	na[i + 1] = na[i] + 1;
      }else{
	na[i + 1] = na[i];
      }
    }
    // cout << "ss :"<< ss << endl;
    // REP(i,m){
    //   cout << na[i] << endl;
    // }
    ///////////////
    REP(i,m){
      if(ss[i] == 'D'){
	ans += (ll)na[i];
      }
    }
  }
  cout << ans << endl;
}
