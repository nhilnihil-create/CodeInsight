#include<bits/stdc++.h>
#include<cctype>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define reps(i,n) for (int i=1;i<=(n);i++)
#define rrep(i,n) for (int i=(n)-1;i>=0;i--)
#define rreps(i,n) for (int i=(n);i>0;i--)
#define all(v) (v).begin(),(v).end()
#define pi 3.1415926535897932384
#define E9 1000000000
#define eps 1e-4
#define pii pair<int,int>
template<class T> inline bool chmin(T &a, T b) {if (a>b) {a = b; return 1;} return 0;};
template<class T> inline bool chmax(T &a, T b) {if (a<b) {a = b; return 1;} return 0;};
typedef long long int ll;
const long long INF = 1LL << 60;


int N, A, B, C;
int l[10];
ll dfs(vector<int> &vec, ll &ans){
  if ((int)vec.size()==N){
    /*ここに処理を書く*/
    int a[3] = {};
    int nonzero = 0;
    rep(i,N){
      if (vec[i]==3) continue;
      
      a[vec[i]] += l[i];
      nonzero++;
    }
    if (nonzero<3 || a[0]==0 || a[1]==0 || a[2]==0) return INF;
    ll point = 10*(nonzero - 3);
    point += abs(a[0]-A) + abs(a[1]-B) + abs(a[2]-C);
    return point;
  }

  for (int v=0;v<=3;v++){ // 狭義の場合はv=l+1とする
    vec.push_back(v);
    ll res = dfs(vec,ans);
    chmin(ans, res);
    vec.pop_back();
  }
  return ans;
}

int main(){
  cin >> N >> A >> B >> C;
  rep(i,N) cin >> l[i];

  vector<int> init;
  ll ans = INF;
  cout << dfs(init, ans) << endl;




  // cout << fixed << setprecision(10);
  
  return 0;
}