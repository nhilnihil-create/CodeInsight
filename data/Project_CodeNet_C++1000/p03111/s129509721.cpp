#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define m1(x) memset(x,-1,sizeof(x))
const int INF = 1e9 + 1;
const ll MOD = 1e9 + 7;
const double PI = 3.141592653589793;

int main(){
  int n, a, b, c;
  cin >> n >> a >> b >> c;
  int use[8];
  int l[8];
  rep(i, n) cin >> l[i];
  int ans = INF;
  for(int i = 0; i < (1<<20); i++){
    int tmp = i;
    int cnt = -30;
    int lena = 0, lenb = 0, lenc = 0;
    rep(j, n){
      use[j] = tmp%4;
      if(use[j]) cnt+=10;
      if(use[j]==1){
        lena += l[j];
      }
      if(use[j]==2){
        lenb += l[j];
      }
      if(use[j]==3){
        lenc += l[j];
      }
      tmp = tmp/4;
    }
    if(lena==0 || lenb==0 || lenc==0) continue;
    ans = min(cnt+abs(a-lena)+abs(b-lenb)+abs(c-lenc), ans);
  }
  cout << ans <<endl;
}
    
    