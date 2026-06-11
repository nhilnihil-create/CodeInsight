#include<bits/stdc++.h>
#define rep(i,f,n) for(ll i=(f); (i) < (n); i++)
#define repe(i,f,n) for(ll i=(f); (i) <= (n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b){if (a < b) { a = b; return true; } return false;}
template<class T> inline bool chmin(T& a, T b){if (a > b) { a = b; return true; } return false;}

ll INF = 1e+18;
int iINF = 1e9;
int MAXI = 1e8 + 1;
using vec = vector<int>;

int 
main()
{
  int N, M; cin >> N >> M;
  int formula = (1900 * M) + ((N - M) * 100);
  int prob = (1 << M);
  cout << formula * prob << endl;
}