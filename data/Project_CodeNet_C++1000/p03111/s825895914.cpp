#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define rep(i, n) for(int i=0;i<n;++i)
#define rrep(i, n) for(int i=n;i>=0;--i)
const int inf=1e9+7;
const ll mod=1e9+7;
const ll big=1e18;
const double PI=2*asin(1);

int main() {
  int N, A, B, C;
  cin>>N>>A>>B>>C;
  int l[N];
  for(int i=0;i<N;++i) cin>>l[i];
  int four = 1;
  for(int i=0;i<=N;++i) four *= 4;
  int tmp1, tmp2;
  vector<int> S;
  bool aru1, aru2, aru3;
  int l1, l2, l3;
  int ans = inf;
  int tmpans;
  for(int bit=0;bit<four;++bit) {
    tmp1 = bit;
    tmp2 = four/4;
    S.clear();
    for(int i=0;i<N;++i) {
      S.push_back(tmp1/tmp2);
      tmp1 %= tmp2;
      tmp2 /= 4;
    }
    aru1 = false;
    aru2 = false;
    aru3 = false;
    l1 = 0;
    l2 = 0;
    l3 = 0;
    tmpans = 0;
    for(int i=0;i<N;++i) {
      if(S[i]==0) {
        if(aru1) tmpans += 10;
        else aru1 = true;
        l1 += l[i];
      }
      if(S[i]==1) {
        if(aru2) tmpans += 10;
        else aru2 = true;
        l2 += l[i];
      }
      if(S[i]==2) {
        if(aru3) tmpans += 10;
        else aru3 = true;
        l3 += l[i];
      }
    }
    if(!aru1 || !aru2 || !aru3) continue;
    tmpans += abs(A-l1);
    tmpans += abs(B-l2);
    tmpans += abs(C-l3);
    ans = min(ans, tmpans);
  }
  cout<<ans<<endl;
}

