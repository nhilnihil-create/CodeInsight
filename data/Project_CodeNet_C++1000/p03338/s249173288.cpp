#include <bits/stdc++.h>
#define REP(i,n) for(ll i = 0; i < (ll)n; i++)
#define FOR(i,a,b) for (ll i=(a);i<(ll)b; i++)
#define ALL(obj) (obj).begin(),(obj).end()
#define INF 1LL << 60
using namespace std;
typedef long long ll;
typedef double db;
typedef string str;
typedef pair<ll,ll> p;
const long long MOD=1000000007;

// vector<p> cut(M); vector<vector<ll> > v(4);
// cut[i].second
// cut[i].first;
// REP(i,M){
//     int a,b;cin>>a>>b;
//     cut[i] = make_pair(b,a);//last first の順番
// }
// for(int i=0; i<N;i++){
// }
// sort(cut.begin(),cut.end()), sort(v.rbegin(), v.rend()); //sort
// char '' str ""
int main(void)
{
    int N; str S; cin>>N>>S;
    int cnt = 0; int ans=0;


    for(int i=1; i<N; i++){
      int alp[40];
      for(int k=0; k<40; k++){
        alp[k]=0;
      }
      for(int j=0; j<i; j++){
        for(int k=0; k<26; k++){
          if(S[j] == ('a'+k) && alp[k]==0) alp[k]++;
        }
      }

      for(int j=i; j<N; j++){
        for(int k=0; k<26; k++){
          if(S[j] == ('a'+k) && alp[k]==1) {cnt++; alp[k]=0;}
        }
      }
      ans = max(ans, cnt);
      cnt = 0;
    }

    cout<<ans<<endl;
    return 0;
}
