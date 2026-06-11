#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (ll i = 0; i < (n); i++)
typedef pair<ll,ll> P;

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}


int main(){

    string s,t;
    cin >> s >> t;

    vector<vector<ll>> sl(26);
    vector<vector<ll>> tl(26);
    
    rep(i,s.size()){
      ll cs,ct;
      cs = s[i] - 'a';
      ct = t[i] - 'a';
      sl[cs].push_back(i);
      tl[ct].push_back(i);
    }

    bool ok = true;
    rep(i,26){
      if(sl[i].size()==0){
        continue;
      }

      ll ct = t[sl[i][0]] - 'a';
      if(tl[ct].size()!=sl[i].size()){
        cout << "No" << endl;
        return 0;
      }else{
        rep(j,sl[i].size()){
          if(sl[i][j]!=tl[ct][j]){
            cout << "No" << endl;
            return 0;
          }
        }
      }
    }

    cout << "Yes" << endl;

    
    return 0;
}