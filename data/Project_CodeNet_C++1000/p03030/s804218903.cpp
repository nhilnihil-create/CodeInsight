#include<bits/stdc++.h>
using namespace std;
const long long MOD = 1e9+7;
#define rep(i,n) for(int i=0;i<n;++i)
typedef long long int ll;
typedef unsigned long long ull;
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
typedef pair<ll,ll> P;


int main()
{
   int n;
   cin>>n;
   pair<pair<string,int>,int> mp[110];
   rep(i,n){
       int a;
       string s;
       cin >>s >>a;
       pair<string,int> p(s,-a);
       mp[i] = pair<pair<string,int>,int>(p,i+1);
   }
   sort(mp,mp+n);
   rep(i,n)cout<<mp[i].second<<endl;
   return 0;
}
