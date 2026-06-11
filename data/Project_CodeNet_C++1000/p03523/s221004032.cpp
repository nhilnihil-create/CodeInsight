#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<ll, ll> pll;
#define all(x) (x).begin(), (x).end()
#define call(x) (x).cbegin(), (x).cend()
#define pb push_back
const double PI = acos(-1);
const int mod = 1e9+7;
const long long INF = (1LL << 60);
ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a / gcd(a,b) * b;}
ll stringcount(string s, char c){return count(s.cbegin(), s.cend(), c);}
bool isInteger(double x){return floor(x) == x;}
ll ceil(const ll a, const ll b){return ((a)+(b)-1)/b;}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s;
  cin >> s;
  for(auto i : {"", "A"}){
    for(auto j : {"", "A"}){
      for(auto k : {"", "A"}){
        for(auto l : {"", "A"}){
          if(s == i + (string)"KIH" + j + (string)"B" + k + (string)"R" + l){
            cout << "YES" << endl;
            return 0;
          }
        }
      }
    }
  }
  cout << "NO" << endl;
  return 0;
}