#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <iomanip>
#include <set>
#include <queue>
#include <stack>
using namespace std;
typedef long long int ll;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define drep(i, n) for(int i = n - 1; i >= 0; i--)
#define YES cout << "YES" << endl
#define Yes cout << "Yes" << endl
#define yes cout << "yes" << endl
#define NO cout << "NO" << endl
#define No cout << "No" << endl
#define no cout << "no" << endl

const int INF = 1001001001;
const ll LINF = 1001002003004005006ll;
const int mod = 1000000007;
#define PI 3.14159265359;

void P(int x) {cout << x << endl;}
void P(long x) {cout << x << endl;}
void P(double x) {cout << x << endl;}
void P(ll x) {cout << x << endl;}
void P(string x) {cout << x << endl;}
void P(char x) {cout << x << endl;}

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}

int main() {
  int n, k;
  cin >> n >> k;
  map<int, int> mp;
  rep (i, n) {
    int tmp;
    cin >> tmp;
    auto itr = mp.find(tmp);
    if (itr != mp.end()) mp[tmp]++;
    else mp[tmp] = 1;
  }

  vector<int> v;
  for (auto itr = mp.begin(); itr != mp.end(); itr++) {
    v.push_back(itr->second);
    // cout << itr->first << "=>" << itr->second << endl;
  }

  sort(v.begin(), v.end());
  int ans = 0;
  int vSize = v.size();
  int i = 0;
  while (vSize > k) {
    ans += v[i];
    vSize--;
    i++;
  }
  P(ans);
  return 0;
}



