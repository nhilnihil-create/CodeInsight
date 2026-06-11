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
#define mt make_tuple
#define pqueue priority_queue
const int inf=1e9+7;
const ll mod=1e9+7;
const ll mod1=998244353;
const ll big=1e18;
const double PI=2*asin(1);

int main() {
  int H, W;
  cin>>H>>W;
  vector<string> S(H);
  for(int i=0;i<H;++i) cin>>S[i];
  int ans[H][W];
  for(int i=0;i<H;++i) {
    for(int j=0;j<W;++j) {
      if(S[i][j]=='#') ans[i][j] = -1;
      else {
        ans[i][j] = 0;
        if(i>0 && S[i-1][j]=='#') ans[i][j]++;
        if(i>0 && j>0 && S[i-1][j-1]=='#') ans[i][j]++;
        if(i>0 && j+1<W && S[i-1][j+1]=='#') ans[i][j]++;
        if(j>0 && S[i][j-1]=='#') ans[i][j]++;
        if(j+1<W && S[i][j+1]=='#') ans[i][j]++;
        if(i+1<H && S[i+1][j]=='#') ans[i][j]++;
        if(i+1<H && j>0 && S[i+1][j-1]=='#') ans[i][j]++;
        if(i+1<H && j+1<W && S[i+1][j+1]=='#') ans[i][j]++;
      }
    }
  }
  for(int i=0;i<H;++i) {
    for(int j=0;j<W;++j) {
      if(ans[i][j]==-1) cout<<'#';
      else cout<<ans[i][j];
    }
    cout<<endl;
  }
}

