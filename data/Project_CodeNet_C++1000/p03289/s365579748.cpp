#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
typedef long long ll;
#define _GLIBCXX_DEBUG
typedef vector<int> vec;
typedef vector<ll> lvec;
typedef vector<char> cvec;
typedef vector<double> dvec;
typedef pair<ll, ll> LP;
typedef tuple<ll, ll, ll> LT;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
#define fs first
#define sc second
int main()	{
  string s;
  cin>>s;
  bool ex=true;
  if(s[0]!='A') ex=false;
  int c=0,cnt=0;
  int n=s.size();
  for(int i=2;i<n-1;i++){
    if(s[i]=='C')
      c++;
  }if(c!=1) ex=false;
  rep(i,n){
    if(isupper(s[i]))
      cnt++;
  }if(cnt!=2) ex=false;
  
  if(ex) cout<<"AC"<<endl;
  else cout<<"WA"<<endl;
}