#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <queue>
#include <cmath>
#include <complex> // complex<double> a(1.2 , 2.3);// real(): 1.2, imag()2.3
using namespace std;

#define MOD 1000000007
#define ll long long
#define ld long double
#define FOR(i,a,b) for(ll i=(ll)a;i<(ll)b;i++)
#define rep(i,n) FOR(i,0,n)
#define pb push_back
#define mp make_pair
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define rmsame(a) sort(all(a)),a.erase(unique(all(a)), a.end())
#define rmvector(a,b) rep(i,a.size())rep(j,b.size())if(a[i]==b[j]){a.erase(a.begin()+i);i--;break;}
template<typename X> bool exist(vector<X> vec, X item){return find(all(vec), item)!=vec.end();}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  string s;cin >> s;
  ll a=0,b=0,c=0;
  rep(i,s.size()){
    if(s[i]=='a') a++;
    else if(s[i]=='b') b++;
    else if(s[i]=='c') c++;
  }

  vector<ll>temp;
  temp.pb(a);
  temp.pb(b);
  temp.pb(c);

  sort(all(temp));
  ll m = temp[0];
  rep(i,3)
    temp[i]-=m;

  rep(i,3){
    if(temp[i]==0) continue;
    if(temp[i]==1) continue;
    else{
      cout << "NO" << endl;
      return 0;
    }
  }

  cout << "YES" << endl;
  //cout << fixed << setprecision(16) << ans << endl;
  return 0;
}
