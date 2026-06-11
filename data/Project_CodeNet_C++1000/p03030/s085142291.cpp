#include<bits/stdc++.h>
 using namespace std;
 #define rep(i,n) for(int i=0;i<n;++i)
 #define all(v) v.begin(), v.end()
 typedef long long int ll;
 typedef unsigned long long ull;
 template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
 template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
 typedef pair<ll,ll> P;
 const long long MOD = 1e9+7;
 const ll INF = 1LL << 60;


 int main(){
     int n;
     cin >> n;
     vector<tuple<string,int,int>> v(n);

     for(int i = 0; i < n; i++){
         string s;
         int p;
         cin >> s >> p;
         v[i] = make_tuple(s,-p,i+1);

     }

     sort(all(v));

     for(auto x: v){
         cout << get<2>(x) << endl;
     }






 }
