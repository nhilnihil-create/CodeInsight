#include<iostream>
#include<cmath>
#include<cstdlib>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<iomanip>
#include<queue>

using namespace std;

typedef long long ll;

typedef std::pair<int, int> ipair;
bool lessPair(const ipair& l, const ipair& r){return l.second < r.second;}
bool morePair(const ipair& l, const ipair& r){return l.second > r.second;}

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

const ll MOD = 1e9 + 7;
// const long long INF = 1LL<<60;
void add(long long &a, long long b) { a += b; if (a >= MOD) a -= MOD; }
void sub(long long &a, long long b) { a -= b; if (a < 0) a += MOD; }
void mul(long long &a, long long b) { a *= b; a %= MOD; }
ll llmin(ll a, ll b) { if (a < b) return a; else return b; }
ll llmax(ll a, ll b) { if (a < b) return b; else return a; }
ll llabs(ll a) { if (a >= 0) return a; else return - a; }
ll llmodpow(ll a, ll n) {
   if (n == 0) return 1;
   ll tmp = llmodpow(a, n / 2);
   mul(tmp, tmp);
   if (n & 1) mul(tmp, a);
   return tmp;
}
int calc(int a, int b) {
   int d = abs(a - b);
   return min(d, 24 - d);
}

int main() {
   int N;
   cin >> N;
   int D[N];
   int log[13];
   memset(log, 0, sizeof(log));
   log[0]++;
   for (int i = 0; i < N; i++) {
      cin >> D[i];
      log[D[i]]++;
   }
  
   int cnt = 13;
   /*
   for (int i = 0; i < cnt; i++) {
      cout << log[i] << endl;
   }
   */
   vector<int> tmp;
   int ans = 0;
   for (int mask = 0; mask < (1 << cnt); mask++) {
      tmp.clear();
      int ansmin = 24;
      for (int i = 0; i < cnt; i++) {
         if (log[i] == 0) continue;
         if (log[i] >= 3) {
            ansmin = 0;
            break;
         }
         if (log[i] == 2) {
            if (i == 0 || i == 12) {
               ansmin = 0;
               break;
            }
            tmp.push_back(i);
            tmp.push_back(24 - i);
         } else if (log[i] == 1) {
            if (((mask >> i) & 1)) {
               tmp.push_back(i);
            } else {
               tmp.push_back(24 - i);
            }
         }
      }
      if (ansmin == 0) {
         chmax(ans, ansmin);
         continue;
      }
      sort(tmp.begin(), tmp.end());
      /*
      for (int i = 0; i < tmp.size(); i++) {
         cout << tmp[i] << " ";
      }
      cout << endl;
      */
      for (int i = 1; i < tmp.size(); i++) {
         chmin(ansmin, calc(tmp[i], tmp[i - 1]));
      }
      chmin(ansmin, calc(tmp[0], tmp[tmp.size() - 1]));
      // cout << ansmin << endl;
      chmax(ans, ansmin);
   }
   cout << ans << endl;
   return 0;
}
