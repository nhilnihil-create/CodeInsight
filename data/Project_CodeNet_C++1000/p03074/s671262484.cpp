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

// ランレングス圧縮(Run Length Encoding)
vector<pair<char,int>> RLE(string S){
  vector<pair<char,int>> p;
  int N = S.size();
  for (int i=0;i<N;i++) {
    if (S[i]==S[i+1]){
      int cnt = 1;
      char c = S[i];
      while (i+1<N && S[i]==S[i+1]) {
        i++;
        cnt++;
      }
      p.push_back({c,cnt});
    }
    else p.push_back({S[i],1});
  }
  return p;
}


int main(){
  int N, K; cin >> N >> K;
  string s; cin >> s;
  vector<int> p;
  if (s[0]=='0') p.push_back(0);
  rep(i,N) {
    if (i<N-1 && s[i]==s[i+1]){
      int cnt = 1;
      while (i+1<N && s[i]==s[i+1]) i++, cnt++;
      p.push_back(cnt);
    }
    else p.push_back(1);
  }
  if (s[N-1]=='0') p.push_back(0);
  int n = p.size();
  vector<int> cumsum(n+1,0);
  rep(i,n) {
    cumsum[i+1] = cumsum[i] + p[i];
  }
  
  int ans = 0;
  for (int left=0;left<n+1;left+=2){
    int right = min(left + 2*K+1, n);
    chmax(ans, cumsum[right]-cumsum[left]);
  }
  cout << ans << endl;
  

  // cout << fixed << setprecision(10);
  
  return 0;
}
