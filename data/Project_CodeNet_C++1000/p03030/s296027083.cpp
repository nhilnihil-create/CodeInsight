#include<bits/stdc++.h>
using namespace std;
const long long INF = 1LL << 60;
template<class T> inline bool chmax(T& a, T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a, T b){if(a>b){a=b;return 1;}return 0;}
#define rep(i,n) for(int i=0;i<n;i++)
#define all(a)  (a).begin(),(a).end()
#define P pair<int, int>
#define ll long long
const int MOD = 1000000007;
//bitset<64>(x).count()
//fixed << setprecision(15) << 

int main(){
  int n, tmp;
  cin >> n;
  pair<pair<string, int>, int> p[n];
  string s;
  rep(i, n){
    cin >> s >> tmp;
    p[i] = make_pair(make_pair(s, tmp*-1), i+1);
  }
  sort(p, p+n);
  rep(i, n)
    cout << p[i].second << endl;
}
