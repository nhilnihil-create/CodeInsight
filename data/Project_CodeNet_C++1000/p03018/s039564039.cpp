#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=1000000007;
const double PI=3.14159265358979;
const ll INF= pow(10,18);
typedef pair<ll,ll> P;
typedef vector<ll> vl;
typedef vector<vl> vvl;
#define for(i,a,b) for(ll i=a;i<b;i++)
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main() {
  string s;
  cin >> s;
  int k=s.size();
  int i=0;
  ll cnt=0;
  ll pre_a=0;
  while(i<k-2){
    if(s[i]=='A'&&s[i+1]=='B'&&s[i+2]=='C'){
      cnt++;
      s[i]='B';
      s[i+1]='C';
      s[i+2]='A';
      cnt +=pre_a;
      i++;
    }
    else{
      if(s[i]=='A'){
        pre_a++;
      }
      else{
        pre_a=0;
      }
    }
      i++;
  }
  cout << cnt << endl;
}