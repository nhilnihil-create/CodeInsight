#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repo(i,n) for(int i = 1; i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define np next_permutation
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define mod 1000000007
#define pi acos(-1.0)
const ll INF = 1LL<<61;
ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : x; }
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }
ll jou(ll N, ll P){if(P==0) return 1;
  if(P%2==0){ll t = jou(N, P/2);return t*t % mod;
  }return (N * jou(N, P-1)) % mod;}  //jou(n,mod-2)で逆元
//intの最大値2147483647 ≒ 2×10^9
//long longの最大値9223372036854775807 ≒ 9×10^18
//'大文字'+=32;    で小文字に
//  cout << fixed << setprecision (20);   小数点以下2０桁まで
//実行時間制約2秒では２×10^8回くらいまで計算できる




int main() {
  string s;
  cin>>s;
  int n=s.size();
  
  if(s=="zyxwvutsrqponmlkjihgfedcba") cout << -1 << endl;

  else{
    if(n!=26){
      vector<bool> p(26);
      rep(i,n){
        p[s[i]-'a']=true;
      }
      cout << s;
      rep(i,26){
        if(!p[i]){
          cout << (char)('a'+i) << endl;
          return 0;
        }
      }
    }
    else{
      int memo;
      char moji;
      for(int i=25;i>0;i--){
        if(s[i-1]<s[i]){
          memo=i-1;
          moji=s[i-1];
          break;
        }
      }
      rep(i,memo){
        cout << s[i];
      }
      string t=s.substr(memo,n-memo);
      sort(all(t));
      int m=t.size();
      rep(i,m){
        if((int)(t[i]-moji)>0){
          cout << t[i] << endl;
          return 0;
        }
      }
    }
  }

}
