#include "bits/stdc++.h"
 
using namespace std;
typedef int64_t ll;
typedef vector<int64_t> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<int> vin;
typedef pair<ll,ll> P;
typedef vector<P> vp;
typedef vector<double> vd;
typedef vector<vd> vvd;
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define SIZE(a) int((a).size())

int main(){
  string s;cin>>s;
  int y,m,d;
  y=(s[0]-'0')*1000+(s[1]-'0')*100+(s[2]-'0')*10+s[3]-'0';
  m=(s[5]-'0')*10+s[6]-'0';
  d=(s[8]-'0')*10+s[9]-'0';
  if(m>4){cout<<"TBD"<<endl;}
  else{{cout<<"Heisei"<<endl;}}
}