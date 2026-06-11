#include<bits/stdc++.h>
#define rep(i,f,n) for(ll i=(f); (i) < (n); i++)
#define repe(i,f,n) for(ll i=(f); (i) <= (n); i++)
using namespace std;
using ll = long long;
#define MOD (ll)1000000007
#define PI 3.14159265359
#define debug(x) cout<<#x<<" :: "<<x<<"\n";
#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\n";
#define debug3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<"\n";
//#define P pair<ll, ll>
#define dvec vector<vector<ll>>
//printf("%.10f\n")
//cout << fixed << setprecision(10);
template<class T> inline bool chmax(T& a, T b){if (a < b) { a = b; return true; } return false;}
template<class T> inline bool chmin(T& a, T b){if (a > b) { a = b; return true; } return false;}
ll INF = 1e+18;
int iINF = 1e9;
int main()
{
  int N, A, B, C; cin >> N >> A >> B >> C;
  vector<int> bam(N);
  rep(i, 0, N) cin >> bam[i];
  int cost = 100000;

  vector<int> bit(3, 0);
  for(bit[0] = 0; bit[0] < (1 << (N)); bit[0]++){
    for(bit[1] = 0; bit[1] < (1 << (N)); bit[1]++){
      if(bit[0] & bit[1]) continue;
      for(bit[2] = 0; bit[2] < (1 << (N)); bit[2]++){
        if(bit[2] & bit[0]) continue;
        if(bit[2] & bit[1]) continue;
        vector<int> mp(3);
        rep(i, 0, 3){
          if(__builtin_popcount(bit[i]) > 0) mp[i] += 10 * (__builtin_popcount(bit[i]) - 1);
        }
        vector<int> len(3, 0);
        rep(i, 0, 3){
          rep(k, 0, N){
            if(bit[i] & (1 << k)) len[i] += bam[k];
          }
        }
        mp[0] += abs(A - len[0]);
        mp[1] += abs(B - len[1]);
        mp[2] += abs(C - len[2]);
        int tmp = 0;
        rep(i, 0, 3) tmp += mp[i];
        if(tmp < cost && bit[0] > 0 && bit[1] > 0 && bit[2] >0) cost = tmp;
      }
    }
  }
  cout << cost << endl;
}
