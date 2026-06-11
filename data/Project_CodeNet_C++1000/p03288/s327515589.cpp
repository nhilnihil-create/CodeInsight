#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define fore(i, l, r) for (int i = (int)(l); i <= (int)(r); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvl;
typedef pair<int, int> pint;
typedef vector<pint> vpint;

const int INF = 1e9;

int main() {
  
int N;
  cin >>N;
  if(N<1200) {
cout <<"ABC" << endl;
  }
else if (N<2800) {
cout << "ARC" << endl;
}
else {
cout << "AGC" << endl;
}
}