#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define erep(i,a,n) for(int i = a;i<=n;i++)
typedef long long ll;
#define int long long
#define vint vector<int>
#define vvint vector<vector<int>>
#define vstring vector<string>
#define vdouble vector<double>
#define vll vector<ll>:
#define vbool vector<bool>
#define INF 1101010101010101010
#define MOD 1000000007
#define P = pair<int,int>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }

signed main(){
  int a,b,q;
  cin >> a >> b >> q;
  vint S(a),T(b),ST;
  rep(i,0,a){
    cin >> S[i];
  }
  rep(i,0,b){
    cin >> T[i];
  }
  vint SV(a),TV(b);
  rep(i,0,a){
    if(T[b-1] < S[i]){
      SV[i] = abs(S[i] - T[b-1]);
    }
    else{
      int l = lower_bound(T.begin(),T.end(),S[i]) - T.begin();
      if(l == 0){
        SV[i] = abs(S[i] - T[l]);
      }
      else{
        SV[i] = min(abs(S[i] - T[l]),abs(S[i] - T[l-1]));
      }
    }
  }
  rep(i,0,b){
    if(S[a-1] < T[i]){
      TV[i] = abs(T[i] - S[a-1]);
    }
    else{
      int l = lower_bound(S.begin(),S.end(),T[i]) - S.begin();
      if(l == 0){
        TV[i] = abs(T[i] - S[l]);
      }
      else{
        TV[i] = min(abs(T[i] - S[l]),abs(T[i] - S[l-1]));
      }
    }
  }
  //rep(i,0,b) cout << TV[i] << endl;
  rep(i,0,q){
    int ans = INF;
    int A;
    cin >> A;
    if(S[a-1] < A){
      ans = min(ans,abs(S[a-1] - A) + SV[a-1]);
      // cout << ans << endl;
    }
    else{
      int l = lower_bound(S.begin(),S.end(),A) - S.begin();
      ans = min(ans,abs(S[l] - A) + SV[l]);
      if(l != 0){
        ans = min(ans,abs(S[l-1] - A) + SV[l-1]);
      }
      // cout << ans << endl;
    }
    if(T[b-1] < A){
      ans = min(ans,abs(T[b-1] - A) + TV[b-1]);
      // cout << ans << endl;
    }
    else{
      int l = lower_bound(T.begin(),T.end(),A) - T.begin();
      ans = min(ans,abs(T[l] - A) + TV[l]);
      if(l != 0){
        ans = min(ans,abs(T[l-1] - A) + TV[l-1]);
      }
      // cout << ans << endl;
    }
    cout << ans << endl;
  }

}