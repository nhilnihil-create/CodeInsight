/**
*    author:  yuya1234
*    created: 13.07.2020 15:42:04
**/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
#define FORV(i,v) for(auto i=v.begin(); i!=v.end();i++)

#define SORT(s) sort((s).begin(),(s).end())
#define SORTD(s) sort((s).rbegin(),(s).rend())
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );

#define SZ(x) ((int)(x).size())
#define MEMSET(v, h) memset((v), h, sizeof(v))

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
int gcd(int a,int b){return b?gcd(b,a%b):a;}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  //std::cout << std::fixed << std::setprecision(15);

  int n,a,b,c,d;
  cin>>n>>a>>b>>c>>d;

  a--;
  b--;
  c--;
  d--;
  string s;
  cin>>s;

  string ans="Yes";

  if(c<d){
    for(;;){
      if(s[b+2]=='.'){
        b+=2;
      }
      else if(s[b+1]=='.'){
        b+=1;
      }
      else{
        ans="No";
        break;
      }
      if(b==d){
        s[b]='#';
        break;
      }
    }
    for(;;){
      if(s[a+2]=='.'){
        a+=2;
      }
      else if(s[a+1]=='.'){
        a+=1;
      }
      else{
        ans="No";
        break;
      }
      if(a==c){
        s[a]='#';
        break;
      }
    }
  }
  else{
    for(;;){
      if(s[a+2]=='.' && a+2!=b){
        a+=2;
      }
      else if(s[a+1]=='.' && a+1!=b){
        a+=1;
      }
      else if(s[b+1]=='.' && b+1<SZ(s)){
        b+=1;
      }
      else if(s[b+2]=='.' && b+2<SZ(s)){
        b+=2;
      }
      else{
        ans="No";
        break;
      }
      if(a==c){
        s[a]='#';
        break;
      }
    }
    for(;;){
      if(b==d){
        s[b]='#';
        break;
      }
      if(s[b+2]=='.'){
        b+=2;
      }
      else if(s[b+1]=='.'){
        b+=1;
      }
      else{
        ans="No";
        break;
      }
    }
  }

  cout<<ans<<endl;

  return 0;
}