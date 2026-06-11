#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
#define all(x) x.begin(),x.end()
#define rep(i,j,n) for (long long i = j; i < (long long)(n); i++)
#define _GLIBCXX_DEBUG
#define MOD 1000000007
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//name[i][j]-> vvl name(i,vl(j))
//map<int,int>mp
//�]���؂�グ�� =>  (a + b - 1) / b 

signed main(){
	string s; cin>>s;
  //string t; cin>>t;
  string u;
  u.push_back(s[0]);
  u.push_back(s[1]);
 int a=stoi(u);
  u="";
  u.push_back(s[2]);
  u.push_back(s[3]);
  int b=stoi(u);
  if(b>0 && b<=12 && a>0 && a<=12) cout<<("AMBIGUOUS");
  else if(a>0 && a<=12) cout<<"MMYY";
  else if(b>0 && b<=12) cout<<"YYMM";
  else cout<<"NA";
	cout<<endl;
 // cout<<"a: "<<a<<" b: "<<b<<endl;
	return 0;
}