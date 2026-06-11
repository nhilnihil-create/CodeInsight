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
#define P pair<int, int>
#define dvec vector<vector<ll>>
//printf("%.10f\n")
//cout << fixed << setprecision(10);
template<class T> inline bool chmax(T& a, T b){if (a < b) { a = b; return true; } return false;}
template<class T> inline bool chmin(T& a, T b){if (a > b) { a = b; return true; } return false;}
ll INF = 1e+18;
int iINF = 1e9;

int N;
int A, B, C;
int ans = iINF;

void
dfs(int len, P a, P b, P c, vector<int> bam)
{
  if(len == N){
    if(a.second < 1 || b.second < 1 || c.second < 1) return ;
    else {
      int mix = 0;
      mix += 10 * (a.second - 1);
      mix += 10 * (b.second - 1);
      mix += 10 * (c.second - 1);
      chmin(ans, abs(A - a.first) + abs(B - b.first) + abs(C - c.first) + mix);
      return ;
    }
  }

  dfs(len + 1, a, b, c, bam);
  dfs(len + 1, {a.first + bam[len], ++a.second}, b, c, bam); --a.second;
  dfs(len + 1, a, {b.first + bam[len], ++b.second}, c, bam); --b.second;
  dfs(len + 1, a, b, {c.first + bam[len], ++c.second}, bam); --c.second;
}

int main()
{
  cin >> N;
  cin >> A >> B >> C;
  vector<int> bam(N);
  rep(i, 0, N) cin >> bam[i];

  dfs(0, {0, 0}, {0, 0}, {0, 0}, bam);
  cout << ans << endl;

}
