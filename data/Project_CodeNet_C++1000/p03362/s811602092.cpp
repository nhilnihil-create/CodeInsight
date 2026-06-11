/* */
#include <cstdio>
#include <cstring>
#include <cassert>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <bitset>
#include <map>
#include <set>
const int MAX_LEN = 1010;
#define GETLINE(x) fgets(x,MAX_LEN,stdin);
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<double, double> dd;
typedef tuple<int, int, int> iii;
typedef vector<ii> vii;
typedef vector<ll> vll;
#ifdef XVENOM
  #define errp(...) fprintf(stderr, __VA_ARGS__)
  #define dbg(...) errp("[%s]: ", #__VA_ARGS__), dbg_str(__VA_ARGS__)
#else
  #define errp(...)
  #define dbg(...)
#endif
template <typename U, typename V> string to_string (pair<U, V>);
string to_string (const string& e_) { return "\"" + e_ + "\""; }
string to_string (char e_) { return "\'" + string(1, e_) + "\'"; }
string to_string (bool e_) { return e_ ? "true" : "false"; }
template <typename T> string to_string (T e_) {
  string s_ = "[ ";
  for (const auto& x_ : e_) s_ += to_string(x_) + " ";
  return s_ + "]";
}
template <typename U, typename V> string to_string (pair<U, V> e_) {
  return "(" + to_string(e_.first) + ", " + to_string(e_.second) + ")";
}
void dbg_str () { errp(" \n"); }
template <typename U, typename... V> void dbg_str (U u, V... v) {
   errp(" %s", to_string(u).c_str()); dbg_str(v...);
}
/* --- */
const ll N=55555;
vll primes;
bitset<N> bs;
void sieve(){
    bs.set();
    bs[0]=bs[1]=0;
    for(ll i=2;i<=N;i++)if(bs[i]){
        for(ll j=i*i;j<=N;j+=i)
            bs[j]=0;
        if(i%5==1)primes.push_back((int)i);
    }
}
int n;
int main () { 
  sieve();
  scanf("%d",&n);
  for(int i=0;i<n;i++)
    printf("%d ",primes[i]);
}