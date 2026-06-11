#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 0

using namespace std;
#define ll long long
#define rep(i,n) for (int i = 0; i < n; i++)
#define MOD (1000000007)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(),(a).end()

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

const ll INF = 1LL << 60;

int main(){
  int n; cin >> n;
  string a,b,c; cin >> a >> b >> c;



  int ans = 0;
  rep(i, n){
    map<char,int> list;
    list[a[i]]++;
    list[b[i]]++;
    list[c[i]]++;
    int maxc = 0;
    for(auto li : list){
      chmax(maxc, li.second);
    }
    ans += 3-maxc;
  }

  std::cout << ans << '\n';
}
