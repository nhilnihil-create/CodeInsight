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
  //vector<int> cost(3, 10000);
  int cost = 100000;

  for(int bit = 0; bit < (1 << N); ++bit){
    for(int bit2 = 0; bit2 < (1 << N); ++bit2){
      if(bit & bit2) continue;
      for(int bit3 = 0; bit3 < (1 << N); ++bit3){
        if(bit3 & bit) continue;
        if(bit3 & bit2) continue;
        vector<int> mp(3);
        if(__builtin_popcount(bit) > 0) mp[0] += 10 * (__builtin_popcount(bit) - 1);
        if(__builtin_popcount(bit2) > 0) mp[1] += 10 * (__builtin_popcount(bit2) - 1);
        if(__builtin_popcount(bit3) > 0) mp[2] += 10 * (__builtin_popcount(bit3) - 1);
        int lena, lenb, lenc; lena = lenb = lenc = 0;
        rep(i, 0, N){
          if(bit & (1 << i)) lena += bam[i];
          if(bit2 & (1 << i)) lenb += bam[i];
          if(bit3 & (1 << i)) lenc += bam[i];
        }
        mp[0] += abs(A - lena);
        mp[1] += abs(B - lenb);
        mp[2] += abs(C - lenc);
        int tmp = 0;
        rep(i, 0, 3) tmp += mp[i];
        if(tmp < cost && lena > 0 && lenb > 0 && lenc >0) cost = tmp;
      }
    }
  }

  cout << cost << endl;
}
